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

	int endTime = vi[1];
	int count = 1;
	for (int i = 2; i < 2 * n;) {
		if (vi[i] > vi[i + 1])
			break;

		if (vi[i] >= endTime)
			count++;
		else {
			i += 2;
		}

		if ((i + 1) < 2 * n)
			endTime = vi[i + 1];
		i += 2;
	}
	cout << count;
}


#endif //INTERVIEW_CPP_TT_H
