#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdio.h>
#define N 10

double A[N][N];
double B[N];
double arr[N] = { 0.0 };
int n;

void my_scanf()
{
    printf("输入数组的阶数:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d行的%d个元素,输入完后回车\n", i + 1, n);
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }
    printf("输入右端的%d个数\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &B[i]);
    }
    //打印
    printf("您输入的数组为\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.4lf ", A[i][j]);
        }
        printf("| %.4lf", B[i]);
        printf("\n");
    }
}
void sorting(int NUM)
{
    //外面的i是为了执行多少次整体流程
    for (int i = NUM; i < n - 1; i++)
    {
        //j代表行，p代表列，jp所代表的就是一个元素
        for (int j = NUM; j < n - i - 1; j++)
        {
            //if是为了比较两行的首元素的大小，从而判断是否执行交换
            if (A[j][NUM] < A[j + 1][NUM])
            {
                //为了实现交换，p代表列，当j在这个循环内为定值时，p++可以让每行的各个元素依次交换
                for (int p = NUM; p < n; p++)
                {
                    double temp = A[j][p];
                    A[j][p] = A[j + 1][p];
                    A[j + 1][p] = temp;
                }
                double temp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = temp;
            }
        }
    }
}

void print()
{
    printf("交换后的数组\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.4lf ", A[i][j]);
        }
        printf("| %.4lf", B[i]);
        printf("\n");
    }
}
void elimination(int NUM)
{
    for (int i = NUM + 1; i < n; i++)
    {
        if (A[i][NUM] != 0)//用于判断该次的首元素是否为0，以避免除以0的情况
        {
            double a = A[NUM][NUM] / A[i][NUM];
            for (int j = NUM; j < n; j++)
            {
                A[i][j] = A[NUM][j] - A[i][j] * a;
            }
            B[i] = B[NUM] - B[i] * a;
        }
    }
}
void result()
{
    for (int i = 1; i <= n; i++)//外层for是用来循环n次
    {
        double temp = B[n - i];
        for (int j = 1; j <= i; j++)
        {
            temp -= A[n - i][n - j] * arr[n - j];
        }
        arr[n - i] = temp / A[n - i][n - i];
    }
}
int main()
{
    // 输入
    my_scanf();
    // 排序，消元
    for (int NUM = 0; NUM < n; NUM++)
    {
        sorting(NUM);
        print();
        elimination(NUM);
        print();
    }
    print();
    // 计算结果
    result();
        // 打印结果
    for (int i = 0; i < n; i++)
    {
        printf("第%d个解为%.4lf",i+1, arr[i]);
    }
    return 0;
}