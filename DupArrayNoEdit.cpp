#include <cstdio>
#include <cstdlib>

/*
���ԣ�
����Ϊ n+1 �������������ַ�ΧΪ 1->n��������������һ���������ظ���
�ҳ��������ظ������֣����ǲ����޸���������� 
*/

int countRange(const int *numbers, int length, int start, int end){
	if (numbers == NULL)
		return 0;
	
	int count = 0;
	
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] > start && numbers[i] <= end)
			++count;
	}
	return count;
}

int getDuplication(const int *numbers, int length){
	/*
	����1��
	����2�� 
	*/
	if (numbers == NULL || length <= 0)
		return -1;
		
	int start = 1;
	int end = length-1;

	while (end >= start){
		int middle = ((end - start) >> 1) + start;
		
		// ͳ�� ������ ��ֵ�� start->middle ��Χ�ĸ��� 
		int count = countRange(numbers, length, start, middle);
		
		// ��ֹ��� 
		if (end == start){
			if (count > 1)
				return start;
			else
				break;
		}
				
		if (count > (middle - start + 1))
			end = middle; // ��� �������� ��Χ�����ֵĸ��� ���� ���Ӳ��ֳ��ȣ�֤��  �ò���һ���������ظ������� 
		else
			start = middle + 1;
	}
	return -1;
} 

int main(){
	return 0;
}
