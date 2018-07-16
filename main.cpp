#include <iostream>
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


int main(int argc, char **argv) {
	cout << "Project Interview-cpp: leetcode" << endl;
	// test_twoSum();
	// test_leet165();

	// 异或操作
	// cout << "二进制运算: " << endl;
	// cout << (2 ^ 2) << '\t' << (2 ^ 0);  // 相同 == 0， 不相同 按位运算
	// dp1();
	dp_lis();
	return 0;
}
