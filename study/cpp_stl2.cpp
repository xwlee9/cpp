#include <iostream>
#include <set>
#include <string>

using namespace std;



int main()
{

  // //set 键值实值一样 通过实值来查找  尽量不要修改
  // // 高效访问 与map一样都是红黑树    log 2^N
  set<string> st;
  st.insert(string("abc"));
  st.insert(string("efg"));
  st.insert(string("hij"));
  st.insert(string("aaa"));             //利用重载运算符进行比较

  st.erase(string("efg"));              //可以直接用"efg" 因为string中重载了运算符
  set<string>::iterator ite = st.begin();
  for (ite; ite != st.end(); ite++)
  {
    cout << *ite <<endl;
  }



  return 0;
}
