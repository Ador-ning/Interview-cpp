//
// Created by ning on 2018/6/20.
//

#ifndef INTERVIEW_CPP_TWOSUM_H
#define INTERVIEW_CPP_TWOSUM_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include "../Algorithm/List.h"

using namespace std;
using namespace Algorithm;
// ==============================   题目1
/*
 * 在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素
 */
vector<int> twoSum(vector<int> &numbers, int target) {
	unordered_map<int, int> m; // 对 value-index 进行存储
	vector<int> result; // 返回 index

	for (int i = 0; i < numbers.size(); i++) {

		if (m.find(numbers[i]) == m.end()) {
			// 在 unordered_map中没有找到第2个数
			m[target - numbers[i]] = i; // 添加 该值需要的第二个数，在后面判断
		} else {
			// 找到
			result.push_back(m[numbers[i]]); // 第一个数
			result.push_back(i); // 第二哥数
		}
	}
	return result;
}

void test_leet1() {
	//int d[4] =;
	//int len = sizeof(d) / sizeof(d[0]);

	vector<int> a = {2, 7, 11, 15};
	int target = 13;
	vector<int> r = twoSum(a, target);

	for (vector<int>::iterator i = r.begin(); i < r.end(); i++)
		cout << *i << '\t';
}

// ==============================   题目2

/*
 * (2 -> 4 -> 3) + (5 -> 6 -> 4) =  7 -> 0 -> 8    342 + 465 = 8071
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	int x = 0, y = 0, carry = 0, sum = 0; // 计算
	ListNode *h = nullptr, **t = &h; // 返回结果链表

	while (l1 != nullptr and l2 != nullptr) {
		x = getValueAndMoveNext(l1);
		y = getValueAndMoveNext(l2); // 链表结束返回 0

		sum = x + y + carry;

		ListNode *node = new ListNode(sum % 10); // 该位结果
		*t = node;
		t = (&node->m_pNext);
		carry = sum / 10; // 进位
	}
	if (carry > 0) {
		ListNode *node = new ListNode(carry % 10);
		*t = node;
	}

	return h;
}

// ==============================   题目3
int LengthOfLongestSubstring(string s) {
	map<int, int> m;
	int MaxLen = 0;
	int LastRepeatPos = -1;

	for (int i = 0; i < s.size(); i++) {

		// 查重复
		if (m.find(s[i]) != m.end() && LastRepeatPos < m[s[i]])
			LastRepeatPos = m[s[i]];

		// 更新最长
		if (i - LastRepeatPos > MaxLen)
			MaxLen = i - LastRepeatPos;

		// 添加
		m[s[i]] = i;
	}

	return MaxLen;
}

void test_leet3() {
	string s = "abcabcbb";
	cout << s << " : " << LengthOfLongestSubstring(s) << endl;

	s = "bbbbb";
	cout << s << " : " << LengthOfLongestSubstring(s) << endl;

	s = "bbabcdb";
	cout << s << " : " << LengthOfLongestSubstring(s) << endl;
}

// ==============================   题目4  ---- 有问题  vector使用
double FindMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	double result = 0.0;
	vector<int> nums3;

	vector<int>::iterator i1 = nums1.begin();
	vector<int>::iterator i2 = nums2.begin();
	vector<int>::iterator i3 = nums3.begin();

	int max_len = (nums1.size() >= nums2.size()) ? nums1.size() : nums2.size();

	// 合并
	for (int i = 0; i < max_len; ++i) {
		if (*i1 > *i2 && i1 != nums2.end()) {
			nums3.insert(i3, *i2);
			i2++;
			i3++;
		} else if (*i1 < *i2 && i2 != nums1.end()) {
			nums3.insert(i3, *i1);
			i1++;
			i3++;
		}
	}
	for (vector<int>::iterator i3 = nums3.begin(); i3 <= nums3.end(); ++i3)
		cout << *i3 << '\t';
}

void test_leet4() {
	vector<int> v1 = {1, 2};
	vector<int> v2 = {3, 4};
	cout << FindMedianSortedArrays(v1, v2) << endl;
}

// ==============================   题目5
/*
 * 最长回文子串
 */
//  找回文子串
string FindPalindrome(string s, int left, int right) {

	int n = s.size();
	while (left >= 0 && right <= n - 1 && s[left] == s[right]) {
		left--;  // 左侧左移
		right++; // 右侧右移
	}
	return s.substr(left + 1, right - left - 1); // (pos, length)
}

string LongestPalindrome_recursive(string s) {
	int n = s.size();

	if (n <= 1)
		return s;

	string longest;
	string str;
	for (int i = 0; i < n - 1; ++i) {
		str = FindPalindrome(s, i, i);
		if (str.size() > longest.size())
			longest = str;

		str = FindPalindrome(s, i, i + 1);
		if (str.size() > longest.size())
			longest = str;
	}
	return longest;
}

void test_leet5() {
	string s("babad");
	cout << LongestPalindrome_recursive(s);
}

// ==============================   题目8  string to int (32)
int64_t MIN_32int = pow(-2, 31);
int64_t MAX_32int = pow(2, 31) - 1;

int MyAtoi(string s) {
	int n = s.size();

	if (n <= 0)
		return 0;

	int64_t result = 0;

	int tagNE = 0; // - 标志
	int tagPO = 0; // + 标志
	int tagNUM = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == ' ') {// 空白符， 越过
			if (tagNUM == 1 && (('0' <= s[i + 1] && s[i + 1] <= '9'))) // 数字中出现空白符
				return 0;
			if ((tagNE == 1 || tagPO == 1) && s[i + 1] == ' ')
				return 0;
			continue;
		}

		if (s[i] == '+') // 正数
		{
			tagPO = 1;
			if (tagNUM == 1 && result == 0)
				continue;
			if (tagNUM == 1 && result != 0)
				return 0;
			continue;
		}

		if (s[i] == '-') { // 负数
			tagNE = 1;
			if (tagNUM == 1 && result == 0)
				continue;
			if (tagNUM == 1 && result != 0)
				return 0;
			continue;
		}

		if (tagNE == 1 && tagPO == 1)
			return 0;

		if (s[i] == '.')
			return result;

		if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) // 遇到字母，结束
		{
			// 判断越界
			if (result > MAX_32int || -result < MIN_32int) {
				if (tagNE == 1)
					return MIN_32int;
				return MAX_32int;
			}

			if (tagNE == 1)
				return -result;
			return result;
		}

		if ('0' <= s[i] && s[i] <= '9') {// 数字
			tagNUM = 1;
			result = s[i] - '0' + result * 10;
		}
	}

	// 判断越界
	if (result > MAX_32int || -result < MIN_32int) {
		if (tagNE == 1)
			return MIN_32int;
		return MAX_32int;
	}

	if (tagNE == 1)
		return -result;
	return result;
}

void test_leet8() {
	string s1 = "4.236688";
	string s2 = "   -+42";
	string s3 = "4193 with words";
	string s4 = "words and 987";
	string s5 = "-91283472332";
	string s6 = "0-1"; // "99-1"

	cout << MyAtoi(s6) << endl;
	cout << to_string(91283472332) << endl;
}

// ============================== 题目14
// 查找字符串数组中的最长公共前缀, 输入只有 a->z
string LongestCommonPrefix(vector<string> &strs) {
	string prefix = "";

	if (strs.size() <= 0)
		return prefix;

	for (int i = 0; i <= strs[0].size(); i++) {
		string w = strs[0].substr(0, i); //
		bool match = true;

		for (int j = 1; j < strs.size(); ++j) {
			if (i > strs[j].size() || w != strs[j].substr(0, i)) {
				match = false; // 1. 长度
				break;         // 2. 不匹配
			}
		}

		if (!match) // match == false
			return prefix;
		prefix = w;
	}
	return prefix;
}

void test_leet14() {
	vector<string> strs1 = {"dog", "racecar", "car"};
	vector<string> strs2 = {"flower", "flow", "flight"};
	cout << LongestCommonPrefix(strs1) << endl;
	cout << LongestCommonPrefix(strs2) << endl;
}

// ============================== 题目17 电话号码字母组合
vector<string> letterCombination(string digits) {
	char phone[10][4] = {{' ',  '\0', '\0', '\0'}, //0
	                     {'\0', '\0', '\0', '\0'}, //1
	                     {'a',  'b',  'c',  '\0'}, //2
	                     {'d',  'e',  'f',  '\0'}, //3
	                     {'g',  'h',  'i',  '\0'}, //4
	                     {'j',  'k',  'l',  '\0'}, //5
	                     {'m',  'n',  'o',  '\0'}, //6
	                     {'p',  'q',  'r',  's'}, //7
	                     {'t',  'u',  'v',  '\0'}, //8
	                     {'w',  'x',  'y',  'z'}  //9
	};

	vector<string> result;

	if (digits.size() <= 0) {
		result.push_back("");
		return result;
	} // base

	for (int i = 0; i < digits.size(); i++) {

		if (!isdigit(digits[i])) {
			vector<string> r;
			return r;
		} // base : not a digit

		int d = digits[i] - '0';
		if (result.size() <= 0) { //
			for (int j = 0; j < 4 && phone[d][j] != '\0'; j++) {
				string s;
				s += phone[d][j];
				result.push_back(s);
			}
			continue;
		}

		vector<string> r;
		for (int j = 0; j < result.size(); j++) {
			for (int k = 0; k < 4 && phone[d][k] != '\0'; k++) {
				string s = result[j] + phone[d][k];
				//sort(s.begin(), s.end());
				r.push_back(s);
			}
		}
		result = r;
	}
	return result;
}

void test_leet17() {
	letterCombination("23");
}

// ============================== 题目19 Remove Nth Node From End of List
ListNode *RemoveNthFromEnd(ListNode *head, int n) {
	if (head == nullptr || n == 0)
		return head;
	if (n == 1 && head->m_pNext == nullptr)
		return nullptr;

	ListNode *pre = head;
	ListNode *next = nullptr; // 指向被删除结点，上一个结点
	ListNode *pDelete = nullptr; // 指向被删除结点

	int num = 0;
	int k = n;
	while (n > 0) {
		pre = pre->m_pNext;
		num += 1;
		if (pre == nullptr)
			if (num == k) // list length == n
			{
				head = head->m_pNext;
				return head;
			} else
				return head; // list length < n
		n--;
	}
	next = head;
	// pre指向最后一个结点
	// next指向被删除上一个结点
	while (pre->m_pNext != nullptr) {
		pre = pre->m_pNext;
		next = next->m_pNext;
	}
	pDelete = next->m_pNext;
	next->m_pNext = pDelete->m_pNext; // 改连接

	// delete pDelete;
	// pDelete = nullptr;
	return head;
}

void test_leet19() {
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(4);
	//ListNode l5(5);

	ConnectListNodes(&l1, &l2);
	ConnectListNodes(&l2, &l3);
	ConnectListNodes(&l3, &l4);
	//ConnectListNodes(&l4, &l5);
	PrintList(RemoveNthFromEnd(&l1, 4));
}

// ============================== 题目20 括号匹配 () / {} / [] -- 利用栈
bool isValid(string s) {
	stack<char> st;

	for (auto ch:s) {
		if (ch == '{' || ch == '[' || ch == '(')
			st.push(ch);
		else if (ch == '}' || ch == ']' || ch == ')') {
			if (st.empty())
				return false;

			char sch = st.top();
			if ((ch == '}' && sch == '{') || (ch == ']' && sch == '[') || (ch == ')' && sch == '('))
				st.pop();
			else
				return false;
		} else
			return false;
	}
	return st.empty();
}

#endif //INTERVIEW_CPP_TWOSUM_H
