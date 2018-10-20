//
// Created by ning on 2018/8/26.
//

#ifndef INTERVIEW_CPP_TT2_H
#define INTERVIEW_CPP_TT2_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

namespace Campus {
	/*  测试用例
helloworld
hdlrowolle      out -- "Yead"
2
helloworld
worldhello      out -- "Yeah"
2
abcde
acbde       out -- "Sad"
*/
	bool helper(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;

		for (int i = 0; i < s1.size(); i++) {
			// 1. 顺时针
			string res1 = s1.substr(i, s1.size() - 1) + s1.substr(0, i - 0);
			if (res1 == s2)
				return true;

			// 2. 逆时针
			string t = s1.substr(i, s1.size() - 1);
			reverse(t.begin(), t.end());
			string res2 = s1.substr(0, i - 0) + t;
			cout << res1 << ' ' << res2 << ' ' << s2 << endl;
			if (res2 == s2)
				return true;
		}
	}

	void test3() {
		int times;
		cin >> times;

		vector<string> in;
		while (times--) {
			int numbers;
			cin >> numbers;

			for (int i = 0; i < numbers; i++) {
				string t;
				cin >> t;
				in.push_back(t);
			} // 输入结束

			int tag = false;
			for (int i = 1; i < in.size(); i++) {
				if (helper(in[0], in[i])) {
					cout << "Yeah" << endl;
					cout << in[0] << ' ' << in[i] << endl;
					tag = true;
					break;
				}
			}
			if (!tag)
				cout << "Sad" << endl;
			in.clear();
		}
	}

	void parse1(string s) {
		int index1;
		int index2;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '-')
				index1 = i;
			else if (s[i] == '=')
				index2 = i;
		}

		string c1 = s.substr(0, 1);
		string c2 = s.substr(index1 + 2, 1);
		string cn = s.substr(index2 + 2, index1 - 1 - index2 - 2);

		cout << c1 << ' ' << c2 << ' ' << cn << endl;

	}

	// 1. 解析 字符串 "a = 0 - b" -- 遍历存储结构
	void test5() {

	}
}
#endif //INTERVIEW_CPP_TT2_H
