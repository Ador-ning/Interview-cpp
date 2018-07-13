//
// Created by ning on 2018/7/13.
//

#ifndef INTERVIEW_CPP_DP_H
#define INTERVIEW_CPP_DP_H

#include <iostream>

using namespace std;

// ============================== 1元 3元 5元硬币，如何用最少的硬币凑11元？
void dp1() {
	int cons[3] = {1, 3, 5};

	int value;
	while (cin >> value) {
		int *arr = new int[value];

		arr[0] = 0;
		for (int i = 1; i <= value; i++) {
			int cons1 = i - 1;
			int cons3 = i - 3;
			int cons5 = i - 5;  // 一次， 剩余的钱数 // 前面有结果

			// 状态转移方程 d(i) = min{d(i-vj)+1}, vj是第j个硬币币值
			int minConsSum = arr[cons1];    // 1元
			int lastCons = cons1;

			// 3元
			if (cons3 >= 0 && arr[cons3] < minConsSum) {
				minConsSum = arr[cons3];
				lastCons = cons3;
			}

			// 5元
			if (cons5 >= 0 && arr[cons5] < minConsSum) {
				minConsSum = arr[cons5];
				lastCons = cons5;
			}

			// 赋值
			arr[i] = minConsSum + 1;

			cout << i << '\t' << arr[i] << '\t' << lastCons << endl;
		}

		cout << endl;
	}
}


#endif //INTERVIEW_CPP_DP_H
