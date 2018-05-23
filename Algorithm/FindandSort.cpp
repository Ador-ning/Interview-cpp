
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

/*
提示： 如果是在 排序的数组（或者部分排序的数组）中查找一个数字或者统计数字出现的次数，使用二分查找
*/

void Swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	// printf("a: %d\tb:%d", *a, *b);
}


int RandomInRange(int index1, int index2) {
	if (index1 >= index2) {
		printf("Invalid range index.\n");
		return -125;
	} else {
		return (rand() % (index2 - index1 + 1) + index1);
	}

}

int Partition(int data[], int length, int start, int end) {
	if (data == NULL || length <= 0 || start < 0 || end >= length) {
		std::logic_error ex("Invalid parameters.\n");
		throw new std::exception(ex);
	}

	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);

	int small = start - 1;

	for (index = start; index < end; ++index) {
		if (data[index] < data[end]) {
			++small;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}

	++small;
	Swap(&data[small], &data[end]);

	return small;
}


void QuickSort(int data[], int length, int start, int end) {
	if (start == end)
		return;

	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	else (index < end)
	QuickSort(data, length, index + 1, end);
}

int main() {
	int a = 0;
	int b = 9;
	// Swap(&a,&b);
	// printf("%d", RandomInRange(a, b));
	return 0;
}