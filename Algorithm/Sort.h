//
// Created by ning on 2018/8/27.
//

#ifndef INTERVIEW_CPP_SORT_H
#define INTERVIEW_CPP_SORT_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

namespace Algorithm {
// in data format: 122 33 22 88 9 0 7 3 2 12
	vector<int> stringToIntVector1(string &s) {
		vector<int> res;
		// vector<string> vs;
		string str_tmp = "";
		int index = 0;
		while (true) {
			index = s.find(" ");
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

/*
 建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。
 */
// 1. 归并排序
	vector<int> merge_(const vector<int> &left, const vector<int> &right) {
		vector<int> res;

		if (left.size() <= 0)
			res = right;
		else if (right.size() <= 0)
			res = left;
		else {
			int i = 0;
			int j = 0;
			while (i < left.size() && j < right.size()) {
				if (left[i] < right[j]) {
					res.push_back(left[i]);
					i++;
				} else {
					res.push_back(right[j]);
					j++;
				}
			}

			while (i < left.size()) {
				res.push_back(left[i]);
				i++;
			}

			while (j < right.size()) {
				res.push_back(right[j]);
				j++;
			}
		}
		// test
		/*
		cout << "Left data: ";
		for (int i = 0; i < left.size(); ++i)
			cout << left[i] << ' ';
		cout << endl;
		cout << "Right data: ";
		for (int i = 0; i < right.size(); ++i)
			cout << right[i] << ' ';
		cout << endl;

		cout << "Merge result: ";
		for (int i = 0; i < res.size(); ++i)
			cout << res[i] << ' ';
		cout << endl;
		*/
		return res;
	}

	vector<int> mergeSort(const vector<int> &arr) {
		if (arr.size() < 2)
			return arr; // length = 1

		int middle = arr.size() / 2; // 划分
		vector<int> left, right;

		for (int i = 0; i < arr.size(); ++i) {
			if (i < middle)
				left.push_back(arr[i]);
			else
				right.push_back(arr[i]);
		}

		return merge_(mergeSort(left), mergeSort(right));
	}

	void testMergeSort() {
		string line;
		getline(cin, line);

		vector<int> in = stringToIntVector1(line);
		cout << "in data: ";
		for (int i = 0; i < in.size(); ++i)
			cout << in[i] << ' ';
		cout << endl;

		vector<int> res = mergeSort(in);

		cout << "Merge sort result: ";
		for (int i = 0; i < res.size(); ++i)
			cout << res[i] << ' ';
		cout << endl;
	}

// 2. 快排
	int partitionQuickSort(vector<int> &arr, int low, int high) {
		int keyValue = arr[low];

		while (low < high) {
			while (low < high && arr[high] >= keyValue) // 大于 keyValue
				--high;
			swap(arr[low], arr[high]);
			while (low < high && arr[low] < keyValue)
				++low;
			swap(arr[low], arr[high]);
		}

		return low; // keyValue index
	}

	void quickSort(vector<int> &arr, int low, int high) {
		if (low < high) {
			int keyIndex = partitionQuickSort(arr, low, high); // 划分
			quickSort(arr, low, keyIndex - 1); // 分治
			quickSort(arr, keyIndex + 1, high);
		}
	}

	void testQuickSort() {
		string line;
		getline(cin, line);

		vector<int> in = stringToIntVector1(line);

		quickSort(in, 0, in.size() - 1);

		cout << "Quick sort result: ";
		for (int i = 0; i < in.size(); ++i)
			cout << in[i] << ' ';
	}

// 3. 堆排序
/*
 初始时把要排序的n个数的序列看作是一棵顺序存储的二叉树（一维数组存储二叉树），调整它们的存储序，使之成为一个堆，将堆顶元素输出，得到n 个元素中最小(或最大)的元素，这时堆的根节点的数最小（或者最大）。然后对前面(n-1)个元素重新调整使之成为堆，输出堆顶元素，得到n 个元素中次小(或次大)的元素。依此类推，直到只有两个节点的堆，并对它们作交换，最后得到有n个节点的有序序列。称这个过程为堆排序
 */
// 堆调整
	void heapAdjust(vector<int> &arr, int i) {
		int tmp = arr[i];
		int childIndex = 2 * i + 1; // 左孩子

		while (childIndex < arr.size()) {
			if (childIndex + 1 < arr.size() && arr[childIndex] < arr[childIndex + 1])
				++childIndex;
			if (arr[i] < arr[childIndex]) { // 如果较大的子结点大于父结点
				arr[i] = arr[childIndex];
				i = childIndex;
				childIndex = 2 * i + 1; // 向下调整
			} else // 不需要调整
				break;
			arr[i] = tmp;
		}
	}

	void buildHeap(vector<int> &arr) {
		if (arr.size() <= 0)
			return;

		for (int i = (arr.size() - 1) / 2; i >= 0; --i)
			heapAdjust(arr, i);
	}

	void heapSort(vector<int> &arr) {
		buildHeap(arr);
		cout << "Build heap: ";
		for (int i = 0; i < arr.size(); ++i)
			cout << arr[i] << ' ';

		cout << endl;
		cout << "Heap sort: ";

		for (int i = arr.size() - 1; i > 0; --i) {

			cout << arr[0] << ' ';
			arr[0] = arr[i]; // 换最小值至堆顶
			arr.pop_back(); // 删除
			heapAdjust(arr, 0); // 自堆顶向下调整
		}
		cout << endl;
	}

	void testHeapSort() {
		string line;
		getline(cin, line);

		vector<int> in = stringToIntVector1(line);
		cout << "In data: ";
		for (int i = 0; i < in.size(); ++i)
			cout << in[i] << ' ';
		cout << endl;
		heapSort(in);
	}

// 4. 计数排序
	void countSort(vector<int> arr) {
		if (arr.size() <= 0)
			return;
		map<int, int> mi; // key -> value

		for (int i = 0; i < arr.size(); i++) {
			if (mi.find(arr[i]) != mi.end())
				mi[arr[i]]++;
			else
				mi[arr[i]] = 1;
		}

		cout << "Count sort result: ";
		map<int, int>::iterator it;
		for (it = mi.begin(); it != mi.end(); ++it) {

			while ((*it).second--) {
				cout << (*it).first << ' ';
			}
		}
		cout << endl;
	}

	void testCountSort() {
		string line;
		getline(cin, line);

		vector<int> in = stringToIntVector1(line);
		countSort(in);
	}

// 5. 桶排序
/*
 工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排)
 */
	void bucketSort(vector<int> arr, int bucketSize) {
		if (arr.size() <= 0 || bucketSize <= 0)
			return;

		int i = 0;
		int minValue = arr[0];
		int maxValue = arr[0];

		for (int i = 1; i < arr.size(); ++i) {
			if (arr[i] < minValue)
				minValue = arr[i];
			if (arr[i] > maxValue)
				maxValue = arr[i];
		}

		// 桶初始化
		int bucketCount = (maxValue - minValue) / bucketSize + 1; // 桶数量  每个桶最所数量
		vector<vector<int>> buckets(bucketCount);

		// 按大小顺序划分桶
		for (int i = 0; i < arr.size(); ++i) {
			buckets[(arr[i] - minValue) / bucketSize].push_back(arr[i]);
		}

		arr.clear();
		for (int i = 0; i < buckets.size(); ++i) {
			quickSort(buckets[i], 0, buckets[i].size() - 1); // 对桶排序
			for (int j = 0; j < buckets[i].size(); ++j)
				arr.push_back(buckets[i][j]);
		}

		cout << "Bucket sort result: ";
		for (int i = 0; i < arr.size(); ++i)
			cout << arr[i] << ' ';
		cout << endl;
	}

	void testBucketSort() {
		string line;
		getline(cin, line);

		vector<int> in = stringToIntVector1(line);
		bucketSort(in, 3);
	}

// 6. 基数排序
	int getMax(const vector<int> arr) {
		int res = INT32_MIN;
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i] > res)
				res = arr[i];
		}
		return res;
	}

	void countSort(vector<int> &arr, int exp) {
		vector<int> output(arr.size(), 0);

		int i;
		vector<int> buckets(10, 0);

		// 将数据出现的次数存储
		for (int i = 0; i < arr.size(); ++i) {
			buckets[(arr[i] / exp) % 10]++;
		}

		for (i = 1; i < arr.size(); ++i)
			buckets[i] += buckets[i - 1];

		for (int i = arr.size() - 1; i >= 0; --i) {
			output[buckets[(arr[i] / exp) % 10] - 1] = arr[i];
			buckets[(arr[i] / exp) % 10]--;
		}

		for (i = 0; i < arr.size(); ++i)
			arr[i] = output[i];

	}

	void radixSort(vector<int> &arr) {
		if (arr.size() <= 0)
			return;

		int exp; // exp = 1 10 100
		int maxValue = getMax(arr);

		for (exp = 1; maxValue / exp > 0; exp *= 10)
			countSort(arr, exp);
	}
}
#endif //INTERVIEW_CPP_SORT_H
