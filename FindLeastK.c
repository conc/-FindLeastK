#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
void exchange(int *a,int *b);
int FindSmallest(int *Array,int n);
int SplitArrayByFirst(int *a,int n);
int FindLeastK(int *a,int n,int k);
 
 
int main(void)
{
     
    int a[10]={0,3,1,2,4,-1,-8,-77,1000,11}; 
    int result = -2;
         
    result = FindLeastK(a,10,1);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,2);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,3);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,4);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,5);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,6);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,7);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,8);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,9);
    printf("result:%d\n",result);
    result = FindLeastK(a,10,10);
    printf("result:%d\n",result);
    printf("---------\n");
     
    int b[3]={3,3,3}; 
 
    result = FindLeastK(b,3,1);
    printf("result:%d\n",result);
    result = FindLeastK(b,3,2);
    printf("result:%d\n",result);
    result = FindLeastK(b,3,3);
    printf("result:%d\n",result);
     
    return 0;
}
 
/*********************************
函 数 名： FindLeastK
函数功能： 返回第K小元素
传入参数： int *a :数组首地址
           int n  :数组尾标
           int k  :要求的第K小元素 
返 回 值: 第K小元素 
*********************************/
int FindLeastK(int *a,int n,int k)
{   
    int result = -1;
    int SplitResult = 0;
    int *CopyArraya = NULL;
     
    /*复制数组，不要破坏原数组*/
    CopyArraya = (int *)malloc(sizeof(int)*n);
    if (CopyArraya == NULL)
    {
        printf("malloc ERROR!\n");
        return -1;
    }
    memcpy(CopyArraya,a,sizeof(int)*n);
 
    if (k<0)
    {
        printf("k must > 0!");
        return -1;
    }   
    if (k==1)/*k为1时表示查找最小元素即可*/
    {
         result = FindSmallest(CopyArraya,n);
         free(CopyArraya);
         return result;
    }
 
    SplitResult = SplitArrayByFirst(CopyArraya,n);
    if (SplitResult <0)
    {
        printf("ERROR\n");
        free(CopyArraya);
        return -1;
    }
     
    if (SplitResult+1 > k)
    {
        result = FindLeastK(CopyArraya,SplitResult,k);
        free(CopyArraya);
        return result;
    }
    else if (SplitResult+1 == k)
    {
        result = CopyArraya[SplitResult];
        free(CopyArraya);
        return result;
    }
    else
    {
        result = FindLeastK(CopyArraya+SplitResult+1,n-SplitResult-1,k-SplitResult-1);
        free(CopyArraya);
        return result;
    }
     
    return 0;
}
 
/*********************************
函 数 名： exchange
函数功能： 交换2个元素 
传入参数： int a;int b
返 回 值: 无 
*********************************/
void exchange(int *a,int *b)
{
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
    return;
}
 
/*********************************
函 数 名： FindSmallest
函数功能： 查找数组中最小元素 
传入参数： int *Array,int n；数组名和数组元素个数 
返 回 值:  数组最小元素 
*********************************/
int FindSmallest(int *Array,int n)
{
    int i=0;
    int Smallest =Array[0];
     
    for (i=1;i<n;i++)
    {
        if (Array[i] < Smallest)
            Smallest = Array[i];
    }
     
    return Smallest;
}
 
/*********************************
函 数 名： SplitArrayByFirst
函数功能： 将传入的数组进行按数组首元素进行划分，使小于等于数组首元素的值放在前面，大于数组首元素的值放在后面 
传入参数： int *a :数组首地址
           int n  :n个元素 
返 回 值: 划分元素a[0]的新位置
*********************************/
int SplitArrayByFirst(int *a,int n)
{
    int i=0;
    int x=a[0];
    int j=1;
 
    if (n == 1)
    {
        return 0;
    }
    if (n < 1)
    {
        return -1;
    }
     
    for (j=1;j<n;j++)
    {
        if (a[j] <= x)
        {
            i++;
            if ( i!= j)
            {
                exchange(a+i,a+j);
            }
        }
    }
    exchange(a,a+i);
    return i;
}
