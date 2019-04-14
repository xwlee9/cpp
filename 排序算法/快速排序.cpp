#include <iostream>
using namespace std;

void PrintArray(int arr[], int length)
{
  for(int i = 0; i < length; ++i) cout << arr[i] << " ";
  cout << endl;
}

void QuickSort(int arr[], int start, int end)
{
    int j = end;
    int i = start;
    int temp = arr[start];

    if (i < j)
    {
      while (i < j)
        {
        // right ==> left
        while(i < j && arr[j] >= temp)
        {
          --j;
        }
        if (i < j)
        {
          arr[i] = arr[j];
          ++i;
        }
        while(i < j && arr[i] < temp)
        {
          ++i;
        }
        if (i < j)
        {
          arr[j] = arr[i];
          --j;
        }
      }
      arr[i] = temp;
      QuickSort(arr, start, i-1);
      QuickSort(arr, i+1, end);
  }
}
int main(void)
{
  int MyArr[] = {4,2,8,0,5,7,1,3,6,9};
  int length = sizeof(MyArr) / sizeof(int);
  PrintArray(MyArr, length);
  QuickSort(MyArr, 0, length-1);
  PrintArray(MyArr, length);

  return 0;
}
