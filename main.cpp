#include <iostream>
#include "./BaseCpp/mystrings.h"
#include "Algorithm/List.h"
#include "Algorithm/BinaryTree.h"
//#include "./BaseCpp/oop.h"
#include "Algorithm/ConvertBST.h"
#include "Algorithm/StringUtils.h"
#include "Algorithm/SortedArray.h"

#include "leetcode/leet20.h"
#include "leetcode/leet40.h"
#include "leetcode/leet60.h"


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
	test_leet56();
	return 0;
}
