#include <iostream>
using namespace std;

int main()
{
  int arr[] = {4,2,8,0,5,7,1,3,6,9};
  int length = sizeof(arr) / sizeof(int);
  int temp = 0;
  cout << length << endl;
  for(int i = 1; i < length; ++i)
  {
    // bool flag = true;
    for(int j = 0; j < length-i; ++j)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = false;
      }
    }
    // if (flag) break;
  }
  for(int i = 0; i < length; ++i)
  {
      cout << arr[i] <<endl;
  }

  return 0;
}
