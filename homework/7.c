#include<stdio.h>
#include<memory.h>
#include<string.h>

int main7() {

	//char ch;
	//int a[26];
	//memset(a, 0, 26 * sizeof(int));
	//while((ch = getchar()) != '\n')			//�����ȡ�û����룬ֱ�������س�
	//{
	//	if (ch >= 'A' && ch <= 'Z')			//��ch�Ǵ�дʱ��Ӧ������Ԫ�ؼ�һ
	//	{
	//		a[ch - 'A']++;					//��������ĸ�Ĺ�ϵ	ch = i + 'A'   
	//	}
	//}

	//for (int i = 0; i < 26; i++)			//�������
	//{
	//	if (i % 9 == 0)
	//	{
	//		printf("\n");
	//	}
	//	printf("%c(%d)   ", i + 'A', a[i]);
	//}

//2.
//	int arr[10];
//	int i, j, m = 0, n = 9, count = 0, num;
//
//	printf("Please input ten numbers : ");
//	for (i = 1; i < 11; i++)		//ѭ��ʮ��
//	{
//		scanf("%d", &num);
//
//		if (num % 2 != 0)			//���������������ż�ԣ���ֵ��������ͷ
//		{
//			arr[m] = num;
//			m++;
//			count++;				//������������
//		}else {
//			arr[n] = num;
//			n--;
//		}
//	}
//
//	int temp;
//
//	for (i = 0; i < count - 1; i++)			//����ѡ������
//	{
//		for (j = i + 1; j < count; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//
//	for (i = 0; i < 10 - 1 - count ; i++)				//ż��ð������
//	{
//		for (j = count; j < 10 - 1- i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//
//	for (i = 0; i < 10; i++)				//��������
//	{
//		printf("arr[%d] = %d\n", i, arr[i]);
//	}

//3.
//	int arr[10];
//	int i, j, max_num = 0, min_num = 0, num, temp;
//
//	printf("Please input 10 numbers: ");		
//	for (i = 0; i < 10; i++)				//�������ݣ���ֵ����
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	num = arr[0];
//	for (i = 1; i < 10; i++)				//�ҳ����ֵ������
//	{
//		if (num < arr[i])
//		{
//			num = arr[i];
//			max_num = i;
//		}
//	}
//
//	num = arr[0];
//	for (j = 1; j < 10; j++)				//�ҳ���Сֵ������
//	{
//		if (num > arr[j])
//		{
//			num = arr[j];
//			min_num = j;
//		}
//	}
//
//	temp = arr[max_num];					//�������ֵ����Сֵ
//	arr[max_num] = arr[min_num];
//	arr[min_num] = temp;
//
//	for (i = 0; i < 10; i++)				//�����������
//	{
//		printf("arr[%d] = %d\n", i, arr[i]);
//	}

//4.
	/*int arr[5][5];
	int i, j, sum1 = 0, sum2 = 0, sum3 = 1, sum4 = 1, sum = 0;

	printf("Please input 25 numbers:\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0, j = 0; i < 5; i++, j++)
	{
		sum1 += arr[i][j];
	}

	for (i = 4, j = 0; j < 5; i--, j++)
	{
		sum2 += arr[i][j];
	}
	printf("sum = %d\n", sum2 + sum1 - arr[2][2]);
	sum = 0;

	for (i = 0, j = 0; i < 5; i += 2, j += 2)
	{
		sum3 *= arr[i][j];
	}

	for (i = 4, j = 0; j < 5; i -= 2, j += 2)
	{
		sum4 *= arr[i][j];
	}
	printf("sum = %d\n", sum3 * sum4 / arr[2][2]);*/

	//8.
	/*char str1[60], str2[60];
	int i, j = 0;

	printf("Please input a strings: ");
	gets(str1);

	for (i = 0; i < strlen(str1); i++)
	{
		if (str1[i] != 'c')
		{
			str2[j] = str1[i];
			j++;
		}
	}
	str2[j] = '\0';
	puts(str2);*/

//10.
	//char str1[60], str2[60];
	//int i, j = 0;

	//printf("Please input the frist string: ");
	//gets(str1);
	//printf("Please input the second string: ");
	//gets(str2);

	////printf("%d\n", strlen(str1) + strlen(str2));
	//

	//i = strlen(str1);				//�ҵ�str1��'\0'���ڵ�λ��
	//while (j < strlen(str2))		//�������str2��str1
	//{
	//	str1[i] = str2[j];
	//	j++;
	//	i++;
	//}

	//str1[i] = '\0';

	//printf("%s", str1);
	//return 0;
}

