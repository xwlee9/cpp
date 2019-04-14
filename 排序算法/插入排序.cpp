#include <iostream>
using namespace std;

void PrintArray(int arr[], int length)
{
  for(int i = 0; i < length; ++i) cout << arr[i] << " ";
  cout << endl;
}

void InsertSort(int arr[], int length)
{
  int j;
  int temp;
  for(int i = 1; i < length; i++)
  {
    if (arr[i] < arr[i-1])
    {
      temp = arr[i];
      for (j = i-1; i >= 0 && temp < arr[j]; --j) arr[j+1] = arr[j];
      arr[j+1] = temp;
    }
  }
}

int main()
{
  int MyArr[] = {4,2,8,0,5,7,1,3,6,9};
  int length = sizeof(MyArr) / sizeof(int);
  PrintArray(MyArr, length);
  InsertSort(MyArr, length);
  PrintArray(MyArr, length);
  return 0;
}
