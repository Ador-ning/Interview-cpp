#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <math.h>
#include <stdio.h>

#include "Algorithm/List.h"
#include "Algorithm/BinaryTree.h"
#include "Algorithm/BST.h"
#include "Algorithm/StringUtils.h"
#include "Algorithm/SortedArray.h"
#include "Algorithm/Heap.h"
#include "Algorithm/Graph.h"
#include "Algorithm/Sort.h"
#include "Algorithm/KMP.h"

#include "leetcode/leet20.h"
#include "leetcode/leet40.h"
#include "leetcode/leet60.h"
#include "leetcode/leet80.h"
#include "leetcode/leet100.h"
#include "leetcode/leet120.h"
#include "leetcode/DP.h"
#include "leetcode/Pack.h"

#include "campus/tx.h"
#include "campus/bd.h"
#include "campus/tt.h"
#include "campus/tt2.h"

#include "Concurrent/thread_test.h"
#include "Concurrent/hierarchical_mutex.h"
#include "Concurrent/hierarchical_mutex.cpp"

#include <numeric>
#include <list>

using namespace std;

void test_ConvertBST() {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}

// find all letter in string
vector<int> findAll(string s, char c) {
	vector<int> result;
	if (s.size() <= 0 || c == ' ')
		return result;

	if (s.find(c) >= s.size())   // 不存在
		return result;

	int i = s.find(c);
	for (; i <= s.size();) {
		result.push_back(i);
		i = s.find(c, i + 1);
	}

	// vector<int>::iterator it;
	// for (it = result.begin(); it != result.end(); it++)
	//      cout << *it << '\t';
	// cout << endl;

	return result;
}

void charConvert(string &s, int i) {
	if ('a' <= s[i] && s[i] <= 'z') {  // 小转大
		s[i] = s[i] - 'a' + 'A';
	} else if ('A' <= s[i] && s[i] <= 'Z') // 大转小
		s[i] = s[i] + 'a' - 'A';
	return;
}

void perm(string s, int k) {
	int n = s.size();
	if (k == n - 1) {
		cout << s << endl;
	} else {
		for (int i = k; i < n; ++i) {
			char tmp = s[i];
			s[i] = s[k];
			s[k] = tmp;
			perm(s, k + 1);
		}
	}
}

bool duplicate(int numbers[], int length, int *duplication) {
	if (length <= 1)
		return false;

	map<int, int> m;
	for (int i = 0; i < length; i++) {
		if (m.find(numbers[i]) == m.end())
			m[numbers[i]] = 1;
		else {
			m[numbers[i]]++;
		}
	}

	bool tag = false;
	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second > 1) {
			*duplication = it->first;
			tag = true;
			break;
		}
	}
	return tag;
}

string ReverseSentence(string str) {
	if (str.size() <= 1) {
		return str;
	}

	int i = 0;
	while (str[i] == ' ')
		i++;    // 跳过头部空格

	string res = "";
	for (; i < str.size();) {
		int spaceIndex = str.find(' ', i);
		if (spaceIndex < 0) {
			res = str.substr(i, str.size() - i) + ' ' + res;
			break;
		}
		res = str.substr(i, spaceIndex - i) + ' ' + res;
		i = spaceIndex + 1;
	}
	return res;
}

// 0-1背包 -- 逆向输出选择物品
void bag() {
	int num, bag; // 商品数量 背包容量
	cin >> num >> bag;

	vector<pair<int, int>> vp; // 重量 价值

	int m1, m2;
	for (int i = 0; i < num; i++) {
		cin >> m1 >> m2;
		vp.push_back(make_pair(m1, m2));
	}

	int dp[200][2000]; // index bag

	for (int j = 1; j <= bag; j++) {
		if (vp[vp.size() - 1].first <= j)
			dp[vp.size() - 1][j] = vp[vp.size() - 1].second;

		for (int i = vp.size() - 2; i >= 0; i--) {
			if (j < vp[i].first)
				dp[i][j] = dp[i + 1][j];
			else
				dp[i][j] = max(dp[i + 1][j - vp[i].first] + vp[i].second, dp[i + 1][j]);
		}
	}

	cout << dp[0][bag] << endl;
	if (dp[0][bag] == 0) {
		cout << "No";
		return;
	}

	int k = bag;
	for (int i = 0; i < vp.size(); i++) {
		if (dp[i][k] > dp[i + 1][k]) {
			cout << i + 1 << ' ';
			k -= vp[i].first;
		}
	}
}

char &get_val(string &s, string::size_type ix) {
	return s[ix];
}

bool helper(vector<pair<int, int>> arr, int i, int users, int count) {
	if (arr.size() <= 0)
		return false;

	int start = 0;
	for (; start < arr.size(); ++start) {
		if (i == arr[start].first)
			break;
	}

	helper(arr, arr[start].second, users, count + 1);

	if (count == users)
		return true;
	return false;
}

// STL using
std::ostream &operator<<(ostream &ostr, const std::list<int> &list) {
	for (auto &i : list)
		ostr << ' ' << i;
	return ostr;
}

void stl_using() {

	// 1. std::partialsum()
	vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	cout << "The first 10 even numbers are: ";
	// 2 4 6 8 10 12 14 16 18 20
	// v[n] = v[n-1] + v[0],  1<= n <= v.size()
	partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	cout << "\n";

	// 2 4 8 16 32 64 128 256 512 1024
	partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
	cout << "The first 10 powers of 2 are: ";
	for (auto n:v)
		cout << n << " ";
	cout << "\n";

	// 2. std::list::splice() / merge() / remove()
	/*
	 * Parameters:
	 *  pos -   element before which the content will be inserted
	 *  other - anthoer container to trasfer the content from
	 *  it - the element to transfer from other to *this
	 *  first, last - the range of elements to transfer from other to *this
	 * */
	list<int> list1 = {1, 2, 3, 4, 5};
	list<int> list2 = {10, 20, 30, 40, 50};

	auto it = list1.begin();
	std::advance(it, 2);    //
	list1.splice(it, list2);
	// list1:  1 2 10 20 30 40 50 3 4 5
	// list2:
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;

	list2.splice(list2.begin(), list1, it, list1.end());
	// list1:  1 2 10 20 30 40 50
	// list2:  3 4 5
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;
}

// /Users/ning/Interview-cpp/cmake-build-debug/TestProject -d -o -i
int main(int argc, char **argv) {
	cout << "Test Cpp Project: " << endl;

	stl_using();

	return 0;
}
