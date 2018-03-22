#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
���ԣ� �ַ����пո��滻
���ַ�����ÿ���ո��滻�� "%20" 
*/

/*
�滻�Ļ���˼·�� O(n)ʱ�临�Ӷ�
1. ͳ�� ��Ҫ�滻�� ��Ŀ -> O(n) 
2. ˫ָ�룬 �Ժ���ǰһ���滻���ƶ�  -> O(n)
*/

// length Ϊ�ַ�����ʵ�����������ڻ�����ַ�����ʵ�ʳ��� 
void ReplaceBlank(char str[], int length){
	
	if (str == NULL || length <= 0)
		return;
	
	// RealLength Ϊ�ַ�����ʵ�ʳ���
	int RealLength = 0;
	int NumberBlank = 0;
	
	int i = 0;
	
	while (str[i] != '\0'){
		++RealLength;
		
		if (str[i] == ' ')
			++NumberBlank;	
		++i;
	} // ͳ�Ƴ� �ַ����ĳ��� ��  �ո���Ŀ 
	
	int newlength = RealLength + NumberBlank * 2;
	
	if (newlength > length)
		return; // Ӧ�����·����ڴ�
	
	// �滻
	int IndexOriginal = RealLength;
	int IndexNew = newlength;
	while (IndexOriginal >= 0 && IndexNew > IndexOriginal){
		if (str[IndexOriginal] == ' '){
			str[IndexNew--] = '0';
			str[IndexNew--] = '2';
			str[IndexNew--] = '%';
		}
		else
			str[IndexNew--] = str[IndexOriginal];
		--IndexOriginal;
	} 
} 


// ====================���Դ���====================
void Test(const char *testName, char str[], int length, char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == NULL && str == NULL)
        printf("passed.\n");
    else if(expected == NULL && str != NULL)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

	char str[length] = "hello world!";
    Test("Test1", str, length, "hello%20world!");
}

int main(){
	Test1();
	return 0;
} 
