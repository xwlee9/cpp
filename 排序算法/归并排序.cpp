#include <iostream>
#include <time.h>
#include <sys/timeb.h>
#define MAX 10
using namespace std;

int* CreateArray()
{
    int* arr = (int*)malloc(sizeof(int)*MAX);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < MAX; ++i)
    {
        arr[i] = rand() % MAX;
    }
    return arr;
}
void PrintArray(int arr[],int len)
{
    for (int i = 0; i < MAX; ++i) cout << arr[i] << " ";
    cout << endl;
}
void Merge(int arr[], int start, int end, int mid, int* temp)
{
    int i_start = start;
    int i_end = mid;
    int j_start = mid + 1;
    int j_end = end;
    // 表示辅助空间有多少个元素
    int length = 0;
    // 合并两个有序序列
    while (i_start <= i_end && j_start <= j_end)
    {
        if(arr[i_start] < arr[j_start])
        {
            temp[length] = arr[i_start];
            ++length;
            ++i_start;
        }
        else
        {
            temp[length] = arr[j_start];
            ++length;
            ++j_start;
        }
    }
    // i序列
    while (i_start <= i_end)
    {
        temp[length] = arr[i_start];
        ++i_start;
        ++length;
    }
    // j序列
     while (j_start <= j_end)
    {
        temp[length] = arr[j_start];
        ++j_start;
        ++length;
    }
    for (int i = 0; i < length; ++i)
    {
        // 现在原数据覆盖原始数据
        arr[start + i] = temp[i];
    }
}

void MergeSort(int arr[], int start, int end, int* temp)
{
    if (start >= end) return;
    int mid = (start + end) / 2;
    // 分组
    // 左半边
    MergeSort(arr, start, mid, temp);
    // 右半边
    MergeSort(arr, mid+1, end, temp);
    // 合并
    Merge(arr, start, end, mid, temp);
}
int main(void)
{
    int* MyArr = CreateArray();
    int* temp = (int*)malloc(sizeof(int)*MAX);
    PrintArray(MyArr, MAX);
    MergeSort(MyArr, 0, MAX-1, temp);
    PrintArray(MyArr, MAX);
    free(temp);
    free(MyArr);
}
