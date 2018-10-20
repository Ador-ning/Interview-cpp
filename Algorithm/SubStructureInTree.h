//
// Created by ning on 2018/5/26.
//

#ifndef INTERVIEW_CPP_SUBSTRUCTUREINTREE_H
#define INTERVIEW_CPP_SUBSTRUCTUREINTREE_H

#include "BinaryTree.h"

using namespace std;
using namespace Algorithm;
namespace Algorithm {
// 树的子结构
/*
 * 面试题26：输入两颗二叉树，判断B是不是A的子结构
 */
	bool Equal(double num1, double num2) {
		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
			return true;
		else
			return false;
	}

	bool T1HaveT2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
		if (pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr)
			return false;

		if (!Equal(pRoot1->value, pRoot2->value))
			return false;

		return T1HaveT2(pRoot1->pLeft, pRoot2->pLeft) && T1HaveT2(
				pRoot1->pRight, pRoot2->pRight);
	}

	bool HasSuTree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
		bool result = false;

		if (pRoot1 != nullptr && pRoot2 != nullptr) {
			if (Equal(pRoot1->value, pRoot2->value))
				result = T1HaveT2(pRoot1, pRoot2);
			if (!result)
				result = HasSuTree(pRoot1->pLeft, pRoot2);
			if (!result)
				result = HasSuTree(pRoot1->pRight, pRoot2);
		}
		return result;
	}
}

#endif //INTERVIEW_CPP_SUBSTRUCTUREINTREE_H
