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

class Interval_t {
public:
	Interval_t() : l(0), r(0) {}

	Interval_t(int i, int j) : l(i), r(j) {}

private:
	int l;
	int r;
};

// dfs
void tt1() {

}


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


#endif //INTERVIEW_CPP_TT_H
