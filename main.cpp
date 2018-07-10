#include <iostream>
#include "./BaseCpp/mystrings.h"
#include "Algorithm/List.h"
#include "Algorithm/BinaryTree.h"
//#include "./BaseCpp/oop.h"
#include "Algorithm/BST.h"
#include "Algorithm/StringUtils.h"
#include "Algorithm/SortedArray.h"
#include "Algorithm/Heap.h"

#include "leetcode/leet20.h"
#include "leetcode/leet40.h"
#include "leetcode/leet60.h"
#include "leetcode/leet80.h"
#include "leetcode/leet100.h"
#include "leetcode/leet120.h"


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
	cout << ('0' <= '8' <= '9') << endl;
	return 0;
}
