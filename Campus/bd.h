//
// Created by ning on 2018/8/7.
//

#ifndef INTERVIEW_CPP_BD_H
#define INTERVIEW_CPP_BD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

namespace Campus {
	// 旋转数组最大值
	int test1_bd() {
		cout << "Input a rotate array: " << endl;
		int k;

		string line;
		getline(cin, line);

		vector<int> in_data = stringToIntVector(line);
		int i = 0;

		vector<int>::iterator it;
		for (it = in_data.begin(); it != in_data.end(); it++)
			cout << *it << ' ';
		cout << endl;

		int n = in_data.size();

		if (n <= 0)
			return 0;
		if (n == 1)
			return in_data[0];
		if (n == 2)
			return in_data[0] > in_data[1] ? in_data[0] : in_data[1];

		// 情况3 递增序
		if (in_data[n - 1] > in_data[0])
			return in_data[n - 1];

		i = 0;
		int j = n - 1;
		int mid = (i + j) / 2;
		while (i <= j) {
			// 停止条件
			if (in_data[mid] >= in_data[mid - 1] && in_data[mid] > in_data[mid + 1]) {
				break;
			}

			if (in_data[mid] > in_data[j])  // 情况1
				i = mid + 1;
			else if (in_data[mid] < in_data[i]) // 情况2
				j = mid - 1;

			mid = (i + j) / 2;
		}
		cout << in_data[mid] << endl;

		return in_data[i];
	}
}


#endif //INTERVIEW_CPP_BD_H
