//
// Created by ning on 2018/8/1.
//

#ifndef INTERVIEW_CPP_TX_H
#define INTERVIEW_CPP_TX_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
namespace Campus {
	vector<int> stringToIntVector(string &s) {
		vector<int> res;
		// vector<string> vs;
		string str_tmp = "";
		int index = 0;
		while (true) {
			index = s.find(",");
			if (-1 == index) {
				str_tmp = s.substr(0, s.length());
				// vs.push_back(str_tmp);
				int t = stoi(str_tmp);
				res.push_back(t);
				break;
			}
			str_tmp = s.substr(0, index);
			// vs.push_back(str_tmp);
			int t = stoi(str_tmp);
			res.push_back(t);
			s.erase(0, index + 1);
		}

		return res;
	}

	void test_tx1() {

		string line;

		getline(cin, line);
		int n = stoi(line);
		if (n < 2)
			return;
		line.clear();
		getline(cin, line);

		vector<int> in_data = stringToIntVector(line);
		if (n != in_data.size())
			return;

		sort(in_data.begin(), in_data.end());

		int countMin = 1;
		int countMax = 1;
		for (int i = 2; i < in_data.size(); i++) {
			if (in_data[i] == in_data[1])
				countMin++;
			else
				break;
		}
		for (int i = in_data.size() - 2; i >= 0; i--) {
			if (in_data[i] == in_data[in_data.size() - 1])
				countMax++;
			else
				break;
		}

		cout << countMin << '\t' << countMax << endl;
	}

	// dp 求 s1 s2中相同的字符串
	// 最长公共子序列
#define LENGTH 1000
	int MaxLen[LENGTH][LENGTH];

	int maxLen(string s1, string s2) {
		int length1 = s1.size();
		int length2 = s2.size();
		for (int i = 0; i < length1; i++)
			MaxLen[i][0] = 0;
		for (int i = 0; i < length2; i++)
			MaxLen[0][i] = 0;
		for (int i = 1; i <= length1; i++) {
			for (int j = 1; j <= length2; j++) {
				if (s1[i - 1] == s2[j - 1])
					MaxLen[i][j] = MaxLen[i - 1][j - 1] + 1;
				else
					MaxLen[i][j] = max(MaxLen[i - 1][j], MaxLen[i][j - 1]);
			}
		}
		return MaxLen[length1][length2];
	}

	// 最大 最小， 数值对
	void test_tx3() {
		int num;
		while (cin >> num) {
			map<int, int> myMap;
			bool flag = false;
			for (int i = 0; i < num; i++) {
				int k;
				cin >> k;
				map<int, int>::iterator it;
				it = myMap.find(k);
				if (it != myMap.end()) {
					(*it).second++;
					flag = true;    // 重复数据
				} else
					myMap.insert(make_pair(k, 1));
			}

			map<int, int>::iterator it = myMap.begin(); // 自动按 key 排序

			//  求最小数值对
			int min = 0;
			int minv = -1;
			if (flag) {
				for (; it != myMap.end(); it++) {
					if ((*it).second > 1)
						min += ((*it).second * ((*it).second - 1)) / 2;
				} //最小差元组对数等于所有相等的数构成的元组对
			} else {
				map<int, int>::iterator it2;
				for (it2 = (++myMap.begin()); it2 != myMap.end(); it2++, it++) {
					int k = (*it2).first - (*it).first;
					if (minv == -1 || k < minv) {
						min = (*it).second * (*it2).second;
						minv = k;
					} else if (minv == k) {
						min += (*it).second * (*it2).second;
					}
				}
			}

			// 求最大数字对
			int max;
			if ((*myMap.rbegin()).first != (*myMap.begin()).first)
				max = (*myMap.rbegin()).second * (*myMap.begin()).second;
			else
				max = (*myMap.rbegin()).second * ((*myMap.rbegin()).second - 1) / 2;
			cout << min << " " << max << endl;
		}
	}
}

#endif //INTERVIEW_CPP_TX_H
