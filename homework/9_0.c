#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int GetSumRow(int* p, int num);
int GetMaxRow(int** p, int row, int col);

int main9_0()
{
    int row, col;
    int i, j, ** p, maxrow;

    printf("input row=");  // ������������
    scanf("%d", &row);
    printf("input col=");  // ������������
    scanf("%d", &col);

    // ��������ľ������������������̬����һ����ά���� p
    p = (int**)malloc(row * sizeof(int*));
    for (i = 0; i < row; i++)
        p[i] = (int*)malloc(col * sizeof(int));

    // ͨ������ֵ�Զ�ά�����Ԫ�ظ�ֵ
    printf("input the number:\n");
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", p[i] + j);

    // ���ú��������������������Ԫ��֮�͵����ֵ
    maxrow = GetMaxRow(p, row, col);
    printf("-------------\n");
    printf("maxrow=%d\n", maxrow);

    // �ͷŶ�̬������ڴ�ռ�
    for (i = 0; i < row; i++)
        free(p[i]);
    free(p);
    return 0;
}

// ���������������Ԫ��֮�͵����ֵ
int GetMaxRow(int** p, int row, int col)
{
    int i, max, t;

    max = GetSumRow(p[0], col);
    for (i = 1; i < row; i++)
    {
        t = GetSumRow(p[i], col);
        if (t > max)
            max = t;
    }
    return (max);
}

// ���������ĳ��Ԫ��֮��
int GetSumRow(int* p, int num)
{
    int sum = 0, i;

    for (i = 0; i < num; i++)
    {
        sum += p[i];
    }
    return(sum);
}
