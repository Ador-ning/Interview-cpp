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


// 求约数 -- 不含 1 和 本身
vector<int> YNumber(int n) {
	vector<int> res;
	if (n <= 3)
		return res;

	for (int i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0) {
			res.push_back(i);
			res.push_back(n / i);
		}
	}

	return res;
}

// 如何知道最少次数
static int M = pow(2, 31) - 1;

void helper(int n, int m, int count) {
	if (m == n) {
		if (count < M)
			M = count;
		return;
	}

	if (m < n)
		return; // 越过

	if (n < m) { // 递归其 约数
		vector<int> v = YNumber(n);
		if (v.size() <= 0) // 不能前进
			return;
		count++;
		for (int i = 0; i < v.size(); i++)
			helper(n + v[i], m, count);
	}
}

// 求最大 奇数 约数
int f1(int n) {
	int maxJ = 1;
	for (int i = 2; i < sqrt(n);) {
		if ((n % i) == 0) {
			// n / i -- 是 奇数
			if ((n / i) % 2 == 1 && (n / i) > maxJ)
				maxJ = (n / i);
			else if ((i % 2 == 1)) // n / i 不是奇数
				maxJ = i;
		}
		i += 2;
	}
	return maxJ;
}

/*
 * 10,10
0,0,0,0,0,0,0,0,0,0
0,0,0,1,1,0,1,0,0,0
0,1,0,0,0,0,0,1,0,1
1,0,0,0,0,0,0,0,1,1
0,0,0,1,1,1,0,0,0,1
0,0,0,0,0,0,1,0,1,1
0,1,1,0,0,0,0,0,0,0
0,0,0,1,0,1,0,0,0,0
0,0,1,0,0,1,0,0,0,0
0,1,0,0,0,0,0,0,0,0
 *
 *
 *
 * */

/*
 * string line;
	vector<int> t;
	cin >> line;
	t = stringToIntVector(line);
	if (t.size() != 2)
		return 0;
	int m = t[0];
	int n = t[1];
	if (m <= 0 || m >= 1000 || n <= 0 || n >= 1000)
		return 0;
	vector<vector<int>> mn;
	mn.resize(m * n);
	for (int i = 0; i < m; i++) {
		cin >> line;
		t = stringToIntVector(line);
		mn.push_back(t);
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){

		}
	}
 *
 *
 *
 *
 * */

int main(int argc, char **argv) {
	cout << "Project Interview-cpp: leetcode" << endl;


	return 0;
}
