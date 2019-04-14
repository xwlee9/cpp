#include <iostream>
using namespace std;

void PrintArray(int arr[], int length)
{
  for(int i = 0; i < length; ++i) cout << arr[i] << " ";
  cout << endl;
}
void MySwap(int arr[], int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}
void HeapAdjust(int arr[], int index, int length)
{
  // 当前节点
  int max = index;
  // 左右节点下标
  int lchild = index * 2 + 1;
  int rchild = index * 2 + 2;
  if (lchild < length && arr[lchild] > arr[max]) max = lchild;
  if (rchild < length && arr[rchild] > arr[max]) max = rchild;
  if (max != index)
  {
    // 交换两个节点
    MySwap(arr, max, index);
    HeapAdjust(arr, max, length);
  }
}

void HeapSort(int arr[], int length)
{
  // 初始化堆
  for (int i = length/2 - 1; i >= 0; --i)
  {
    HeapAdjust(arr, i, length);
    // cout << arr[0] << endl;
  }
  for (int i = length - 1; i >= 0; --i)
  {
    MySwap(arr, 0 ,i);
    HeapAdjust(arr, 0, i);
  }
}



int main(void)
{
  int MyArr[] = {4,2,8,0,5,7,1,3,6,9};
  int length = sizeof(MyArr) / sizeof(int);
  PrintArray(MyArr, length);
  HeapSort(MyArr, length);
  PrintArray(MyArr, length);

  return 0;
}
