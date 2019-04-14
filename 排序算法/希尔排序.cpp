#include <iostream>
using namespace std;

void PrintArray(int arr[], int length)
{
  for(int i = 0; i < length; ++i) cout << arr[i] << " ";
  cout << endl;
}

void ShellSort(int arr[], int length)
{
  int incereament = length;
  int i,j,k,temp;
  do
  {
    incereament = incereament / 3 + 1;
    for (i = 0; i < incereament; ++i)
    {
      for(j = i + incereament; j < length; j += incereament)
      {
        if (arr[j] < arr[j - incereament])
        {
          temp = arr[j];
          for(k = j-incereament; k >= 0 && temp< arr[k]; k -= incereament) arr[k + incereament] = arr[k];
          arr[k + incereament] = temp;
        }
      }
    }
  } while(incereament > 1);
}
int main()
{
  int MyArr[] = {4,2,8,0,5,7,1,3,6,9};
  int length = sizeof(MyArr) / sizeof(int);
  PrintArray(MyArr, length);
  ShellSort(MyArr, length);
  PrintArray(MyArr, length);
  return 0;
}
