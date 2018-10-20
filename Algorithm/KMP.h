//
// Created by ning on 2018/7/18.
//

#ifndef INTERVIEW_CPP_KMP_H
#define INTERVIEW_CPP_KMP_H

#include <iostream>
#include <string>

using namespace std;

namespace Algorithm {
// ======================= 前缀函数实现 ======================= //
/*
 *  求 Pattern 串最长前缀 （求解时，满足其 真后缀条件）
 *  规律：匹配失效后，移动距离 s = Pattern 长度 - 其最长前缀
 * */
	void ComputePrefixFunc(string Pattern, int PrefixFunc[]) {
		int iLen = Pattern.size();  // length of Pattern

		int LOLP = 0;  // length of longest prefix  最长前缀
		PrefixFunc[1] = 0;

		// NOCM -- the number of character matched  匹配的字符串长度( 模式串 / 原串 )
		for (int NOCM = 2; NOCM < iLen + 1; NOCM++) {

			while (LOLP > 0 && (Pattern[LOLP] != Pattern[NOCM - 1]))
				LOLP = PrefixFunc[LOLP];    // 继续匹配失效时，     ##############  之前

			if (Pattern[LOLP] == Pattern[NOCM - 1]) // 最长前缀 / 真后缀
				LOLP++;

			PrefixFunc[NOCM] = LOLP;
		}
	}

// ======================= 前缀函数 KMP ======================= //
	void KMPstrMatching(string Target, string Pattern) {
		int PrefixFunc[Pattern.size() + 1]; // 前缀

		int TarLen = Target.size();
		int PatLen = Pattern.size();

		ComputePrefixFunc(Pattern, PrefixFunc);

		int NOCM = 0;  // the number of characters matched

		for (int i = 0; i < TarLen; i++) {
			while (NOCM > 0 && Pattern[NOCM] != Target[i])
				NOCM = PrefixFunc[NOCM];  // 不匹配, 重新移动

			if (Pattern[NOCM] == Target[i]) // 匹配
				NOCM++;

			if (NOCM == PatLen) {
				cout << "KMP String Matching,pattern occurs with shift " << i - PatLen + 1 << endl;
				NOCM = PrefixFunc[NOCM];
			}
		}
	}

	void test_prefix() {
		string p = "abccaeccabca";
		int PrefixFunc[12] = {0};

		ComputePrefixFunc(p, PrefixFunc);

		cout << endl;

		for (int i = 1; i < 12; i++)
			cout << PrefixFunc[i] << '\t';
		cout << endl;
	}

}
#endif //INTERVIEW_CPP_KMP_H
