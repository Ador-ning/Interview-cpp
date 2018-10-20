//
// Created by ning on 2018/8/12.
//

#ifndef INTERVIEW_CPP_TT_H
#define INTERVIEW_CPP_TT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

namespace Campus {
	class Interval_t {
	public:
		Interval_t() : l(0), r(0) {}

		Interval_t(int i, int j) : l(i), r(j) {}

		int l;
		int r;
	};

	// DFS / BFS
	void tt1() {

	}

	// 区间合并 --- 排序合并
	/*
 3
 1,10;32,45
 78,94;5,16
 80,100;200,220;16,32
 * */
	bool comp(Interval_t *a, Interval_t *b) {
		if (a->l > b->l)
			return false;
		return true;
	}

	void tt2() {
		int nums;
		cin >> nums;

		vector<int> vi;
		while (nums--) {
			string line;
			cin >> line;
			int i_begin = 0;
			int number;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == ',' || line[i] == ';') {
					string s = line.substr(i_begin, i - i_begin);
					number = stoi(s);
					if ((i + 1) < line.size())
						i_begin = i + 1;
					vi.push_back(number);
				}
			}
			string s = line.substr(i_begin, line.size() - i_begin);
			number = stoi(s);
			vi.push_back(number);
		}

		vector<Interval_t *> vv;
		for (int i = 0; i < vi.size(); i += 2) {
			Interval_t *tmp = new Interval_t(vi[i], vi[i + 1]);
			vv.push_back(tmp);
		}

		sort(vv.begin(), vv.end(), comp);

		vector<Interval_t *>::iterator it = vv.begin();
		it = it + 1;
		for (; it != vv.end();) {
			if ((*it)->l <= (*(it - 1))->r) { // 合并
				(*(it - 1))->r = (*it)->r;
				vv.erase(it);
			} else {
				it++;
			}
		}

		for (it = vv.begin(); it != vv.end(); it++) {
			cout << (*it)->l << ' ' << (*it)->r << endl;
		}

	}

	// 贪心
	void tt5() {
		int n, m;
		cin >> n;
		cin >> m;

		vector<int> vi;
		vi.resize(2 * n);
		for (int i = 0; i < 2 * n; i++)
			cin >> vi[i];

		int i = 0;

		while (vi[i] > vi[i + 1]) // pass 起始跨天
			i += 2;

		int endTime = vi[++i];
		int count = 1;
		i++;

		for (; i < 2 * n;) {
			if (vi[i] > vi[i + 1]) {    // end
				if (vi[i + 1] == 0) { // another day or not
					count++;
				}
				break;
			}

			if (vi[i] >= endTime) { // can watch
				count++;
				if ((i + 1) < 2 * n)
					endTime = vi[i + 1];
				i += 2;
			} else { // can not watch
				i += 2;
			}
		}
		cout << count;
	}

	// 最长括号匹配
	// "))()()(()(()()())" -- 10 ()(()()())
	int longestValidParentheses() {

		string s;
		getline(cin, s);

		int maxLen = 0;
		int lastError = -1;
		vector<int> stack;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				stack.push_back(i);
			} else if (s[i] == ')') {

				if (stack.size() > 0) { // 情况1
					stack.pop_back();
					int len;

					if (stack.size() == 0) {  // 1.1 -- ))()()
						len = i - lastError;
						cout << "1.1: " << len << ' ' << i << ' ' << lastError << endl;
					} else {
						cout << "1.2: " << i << ' ' << stack.back() << ' ';
						len = i - stack.back(); // 1.2 (()()
						cout << len << endl;
					}

					if (len > maxLen) {
						maxLen = len;
					}
				} else { // 情况 2 -- >>  "))"
					lastError = i;
				}
			}
		}
		cout << maxLen << endl;
		return maxLen;
	}

}
#endif //INTERVIEW_CPP_TT_H
