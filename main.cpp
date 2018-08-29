#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>


#include "./BaseCpp/mystrings.h"
#include "Algorithm/List.h"
#include "Algorithm/BinaryTree.h"
//#include "./BaseCpp/oop.h"
#include "Algorithm/BST.h"
#include "Algorithm/StringUtils.h"
#include "Algorithm/SortedArray.h"
#include "Algorithm/Heap.h"
#include "Algorithm/Graph.h"
#include "Algorithm/Sort.h"

#include "leetcode/leet20.h"
#include "leetcode/leet40.h"
#include "leetcode/leet60.h"
#include "leetcode/leet80.h"
#include "leetcode/leet100.h"
#include "leetcode/leet120.h"
#include "leetcode/DP.h"
#include "leetcode/Pack.h"
#include "Algorithm/KMP.h"

#include "campus/tx.h"
#include "campus/bd.h"
#include "campus/tt.h"
#include "campus/tt2.h"

#include "learn/l1.h"

using namespace std;

void test_BaseCpp() {
	cout << "Begin test BaseCpp:" << endl;
}

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

int main(int argc, char **argv) {
	cout << "Test Cpp Project: " << endl;
	return 0;
}
