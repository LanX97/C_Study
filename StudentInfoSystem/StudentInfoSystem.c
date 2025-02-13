#include<stdio.h>
#include<stdlib.h>

struct stu_info* GetStuInfo(int i);
struct stu_info* stu_lowest_score(struct stu_info** pstu, int amount);
void FreeMemory(struct stu_info** pstu, int amount);
void WriteDataToFile(struct stu_info** pstu, int* pamount);
struct stu_info** ReadDataFromFile(struct stu_info** pstu, int famount, FILE* fp);
void DisplayInfo(struct stu_info** pstu, int amount);


struct stu_info
{
	char stu_no[20];
	float stu_score;
};

int main()
{
	//����1������ѧ����Ϣ�����档����2���ҳɼ���͵ġ�����3������ѱ�����ļ�������4���鿴��������Ϣ

	int amount,famount, i, num;
	int* pamount, *pfamount;
	struct stu_info** pstu = NULL, *pmin;
	FILE* fp;
	enum option1 {YES, NO};
	enum option2 {Confirm, Cancel};

	enum option1 user_option = YES;

	while (user_option == YES) {

		printf("\n\n\n======control board======");
		printf("\n1.new		 2.lowest\n3.display 	 4.add\n5.delate	 6.exit\n\n\n");
		printf("Please choose the operation: ");
		scanf("%d", &num);

		switch (num) {

		case 1:
			do {
				printf("\nPlease input the amount of student: ");				//����ѧ������
				scanf("%d", &amount);
			} while (amount <= 0);

			pamount = &amount;

			pstu = (struct stu_info**)malloc(amount * sizeof(struct stu_info*));			//�������������ڴ�
			if (pstu == NULL)
			{
				printf("no enough memory!");
				return -1;
			}

			for (i = 0; i < amount; i++)			//����ѧ����Ϣ
			{
				pstu[i] = GetStuInfo(i);
			}

			printf("\n\n============result============\n\n");					//��������������
			printf("stu_no		stu_score\n");
			for (i = 0; i < amount; i++)
			{
				printf("%-12s    %-8.2f\n", pstu[i]->stu_no, pstu[i]->stu_score);
			}

			int user_confirm;
			printf("\n\nSave or not?");
			printf("\n\n1.Confirm		2.Cancel\n\n\n");
			while (1) {
				printf("Please choose the operation: ");
				scanf("%d", &user_confirm);
				if (user_confirm - 1 == Confirm)
				{
					WriteDataToFile(pstu, pamount);
					FreeMemory(pstu, amount);
					pstu = NULL;
					break;
				}
				else if (user_confirm - 1 == Cancel) {
					break;
				}
				else {
					printf("Please enter valid options��\n");
				}
			}
			break;

		case 2:
			if (pstu == NULL) {
				fp = fopen("student.dat", "rb");
				if (fp == NULL)
				{
					printf("can't find student.dat!");
					break;
				}
				pfamount = &famount;
				fread(pfamount, 4, 1, fp);
				//printf("%d\n", famount);

				pstu = ReadDataFromFile(pstu, famount, fp);
				if (pstu == NULL)
				{
					printf("no enough memory!");
					return -1;
				}

				fclose(fp);
				pmin = stu_lowest_score(pstu, famount);
				printf("\n==========result==========\n");
				printf("stu_no: %s\n", pmin->stu_no);
				printf("stu_score: %f\n", pmin->stu_score);
				FreeMemory(pstu, famount);
				pstu = NULL;
			}

			break;
		
		case 3:
			if (pstu == NULL) {
				fp = fopen("student.dat", "rb");
				if (fp == NULL)
				{
					printf("can't find student.dat!");
					break;
				}
				pfamount = &famount;
				fread(pfamount, 4, 1, fp);
				//printf("%d\n", famount);

				pstu = ReadDataFromFile(pstu, famount, fp);
				if (pstu == NULL)
				{
					printf("no enough memory!");
					return -1;
				}
				fclose(fp);
				DisplayInfo(pstu, famount);
				FreeMemory(pstu, famount);
				pstu = NULL;
			}
			
			break;

		case 4:
			if (pstu == NULL) {
				fp = fopen("student.dat", "rb+");
				if (fp == NULL)
				{
					printf("can't find student.dat!");
					break;
				}
				fseek(fp, 0L, SEEK_END);

				do {
					printf("\nPlease input the amount of student YOU WANT TO ADD: ");				//����ѧ������
					scanf("%d", &amount);
				} while (amount <= 0);

				pamount = &amount;

				pstu = (struct stu_info**)malloc(amount * sizeof(struct stu_info*));			//�������������ڴ�
				if (pstu == NULL)
				{
					printf("no enough memory!");
					return -1;
				}

				for (i = 0; i < amount; i++)			//����ѧ����Ϣ
				{
					pstu[i] = GetStuInfo(i);
				}

				printf("\n\n============result============\n\n");					//��������������
				printf("stu_no		stu_score\n");
				for (i = 0; i < amount; i++)
				{
					printf("%-12s    %-8.2f\n", pstu[i]->stu_no, pstu[i]->stu_score);
				}

				int user_confirm;
				printf("\n\nSave or not?");
				printf("\n\n1.Confirm		2.Cancel\n\n\n");
				while (1) {
					printf("Please choose the operation: ");
					scanf("%d", &user_confirm);
					if (user_confirm - 1 == Confirm)
					{
						WriteDataToFile(pstu, pamount);
						FreeMemory(pstu, amount);
						pstu = NULL;
						break;
					}
					else if (user_confirm - 1 == Cancel) {
						break;
					}
					else {
						printf("Please enter valid options��\n");
					}
				}
			}
			break;

		case 5:
			if (remove("student.dat") == 0) {
				printf("\nFile '%s' deleted successfully.\n", "student.dat");
				break;
			}
			else {
				perror("Error deleting file");
				exit(0);
			}

		case 6:
			return 0;

		}
	}
}

struct stu_info* GetStuInfo(int i)				//����ѧ����Ϣ
{
	struct stu_info* p;

	p = (struct stu_info*)malloc(sizeof(struct stu_info));
	printf("\n====input %dth student's information====\n", i + 1);
	printf("no: ");
	scanf("%s", p->stu_no);
	printf("score: ");
	scanf("%f", &p->stu_score);
	return(p);
}

struct stu_info* stu_lowest_score(struct stu_info** pstu, int amount)			//�ҳɼ���͵ģ����ؽṹ��ָ��
{
	struct stu_info* pmin;
	int i;
	pmin = pstu[0];
	for (i = 1; i < amount; i++)
	{
		if (pstu[i]->stu_score < pmin->stu_score)
		{
			pmin = pstu[i];
		}
	}
	return(pmin);

}

void FreeMemory(struct stu_info** pstu, int amount)				//�ͷ��ڴ�ռ�ĺ���
{
	int i;
	for (i = 0; i < amount; i++)
		free(pstu[i]);
	free(pstu);
}

void WriteDataToFile(struct stu_info** pstu, int* pamount)			//д��ѧ����Ϣ
{
	FILE* fp;
	int i;

	fp = fopen("student.dat", "wb");
	if (fp == NULL)
	{
		printf("can't create student.dat!");
		FreeMemory(pstu, *pamount);
		exit(0);
	}
	fwrite(pamount, sizeof(int), 1, fp);
	for (i = 0; i < *pamount; i++)
	{
		fwrite(pstu[i], sizeof(struct stu_info), 1, fp);
	}
	fclose(fp); 
}

struct stu_info** ReadDataFromFile(struct stu_info** pstu, int famount, FILE* fp)
{
	int i;
	pstu = (struct stu_info**)malloc(famount * sizeof(struct stu_info*));
	if (pstu == NULL)
		return NULL;

	for (i = 0; i < famount; i++)
	{
		pstu[i] = (struct stu_info*)malloc(sizeof(struct stu_info));
		fread(pstu[i], sizeof(struct stu_info), 1, fp);
	}
	
	return(pstu);
}

void DisplayInfo(struct stu_info** pstu, int amount)
{
	int i;
	printf("stu_no		stu_score\n");
	for (i = 0; i < amount; i++)
	{
		printf("%-12s    %-8.2f\n", pstu[i]->stu_no, pstu[i]->stu_score);
	}
}