//
// Created by ning on 2018/5/26.
//

#ifndef INTERVIEW_CPP_TREE_H
#define INTERVIEW_CPP_TREE_H

#include <vector>
#include <iostream>

using namespace std;

namespace Algorithm {
	struct TreeNode {
		int value; // 结点值
		std::vector<TreeNode *> Children; // 子结点指针 vector
	};

	TreeNode *CreateTreeNode(int value) {

		TreeNode *pNode = new TreeNode();
		pNode->value = valule;

		return pNode;
	}

	void ConnectTreeNode(TreeNode *pParent, TreeNode *pChild) {

		if (pParent != nullptr)
			pParent->Children.push_back(pChild);
	}

	void PrintTreeNode(const TreeNode *pNode) {

		if (pNode != nullptr) {
			cout << "Value of this node is %d." << pNode->value << endl;
			cout << "Its children is as following:" << endl;
			std::vector<TreeNode *>::const_iterator i = pNode->Children.begin();
			while (i < pNode->Children.end()) {
				if (i != nullptr)
					cout << "%d\t" << (*i)->value;
			}
			cout << endl;
		} else
			cout << "This node is null ptr!" << endl;
	}

// 深度优先搜索
	void PrintTree(const TreeNode *pRoot) {
		PrintTreeNode(pRoot);

		if (pRoot != nullptr) {
			std::vector<TreeNode *>::const_iterator i = pRoot->Children.begin();
			while (i < pRoot->Children.end()) {
				PrintTree(*i);
				++i;
			}
		}
	}

	void DestroyTree(TreeNode *pRoot) {
		if (pRoot != nullptr) {

			std::vector<TreeNode *>::iterator i = pRoot->Children.begin();
			while (i < pRoot->Children.end()) {
				DestroyTree(*i);
				++i;
			}
			delete pRoot;
		}
		// pRoot = nullptr;
	}
}

#endif //INTERVIEW_CPP_TREE_H
