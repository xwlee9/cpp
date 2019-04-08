#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

// #pragma warning(disable:xxxx) //去掉代号为xxxx的warning

// stl standard template library
// //========================================算法(最后)
void fun(char c)
{
  cout << c;
}

void FunForeach()    // 遍历函数
{
    string str("hiefaecgra");
    for_each(str.begin(),str.end(),fun); // 头文件<algorithm>
    // sort(str.begin(),str.end());  // 排序 默认从小到大
    sort(str.begin(),str.end(),greater<char>());  //从大到小排序  头文件<functional>
    cout << endl;
    for_each(str.begin(),str.end(),fun);
    cout << endl;
}







int main()
{
  string str;                     // 无参数构建函数
  const char* str1 = str.c_str();

  string str2(5, 'x');            // length 个 ch
  cout << str2.c_str() << endl;

  string str3("abcde");           // 字符串初始化
  cout << str3.c_str() << endl;   // abcde

  string str4("abcdef", 3);       // 参数2 length
  cout << str4.c_str() << endl;   // abc

  string str5 ("abcdefg", 3, 3);  //参数2 index  参数3 length
  cout << str5.c_str() << endl;   // def

  string str6 (str5);
  cout << str6.c_str() << endl;   // def 拷贝构造

  cout << str6;

  string str7("nice");
  cout << str7 << endl;
  // cin >> str7;
  // cout << str7;
// // ========================输出全部
  cout << str7 <<endl;
  cout << str7.c_str() << endl;
// // ========================输出单个字符
  cout << str7[1] << endl;
  cout << str7.at(1) << endl;
// // ========================修改
  str7[1] = 'a';
  cout << str7 << endl;
  str7.at(0) = 'f';
  cout << str7 << endl;

  str7.insert(2, str2);       // 第二个位置插入str2
  cout << str7 << endl;

  str7.insert(2, str3, 0, 2); // 第二个位置插入str3 中的index 为0的开始插入两个值
  cout << str7 << endl;

  str7.insert(0, "mmm");
  str7.insert(0, 3, 'n');
  cout << str7 << endl;       //nnnmmmfaabxxxxxce

  str2 += str3;
  str2 += "zzz";
  cout << str2 <<endl;        //xxxxxabcdezzz

  str2.append("111");
  cout << str2 << endl;       //xxxxxabcdezzz111
  str2.append("222", 2);
  str2.append(2, 'm');
  cout << str2 << endl;       //xxxxxabcdezzz11122mm

  str7 = "xxx";
  str2 = str7;
  cout << str2 << "   " << str7 << endl;      //xxx   xxx

  // cin >> str;
  // cout << str << endl;

  str2.assign("abcdefg", 3);    //赋值
  cout << str2 <<endl;

  str7.erase(1,2);              // 从1开始 删除2个
  cout << str7 <<endl;          // x
  str2.erase(0,str2.length());

// ============================================操作函数
// //比较 < -n     = 0    > n
  string str8("abdahservewpi");
  string str9("abdd");
  cout << (str8 > str9) <<endl;               // 0
  cout << str8.compare(str9) << endl;         // -3
  cout << str8.compare(1,2,str9) << endl;     //1  bd abdd  (index length)

// //拷贝 拷贝自己num个字符到str中 返回值为字符串的个数
  char arrStr[6] = {0};
  str8.copy(arrStr,3,1);                      //bda (number,index)
  cout << arrStr <<endl;

// //查找 指定位置查找 str9 字符 字符串
  cout << str8.find("bd",1) << endl;          // 1 返回index

// //返回字串 (index, num )
  cout << str8.substr(1,5) <<endl;            //bdahs
// //交换 swap
  str8.swap(str9);
  cout << str8 << "   " << str9 << endl;      //abdd   abdahservewpi
// //运算符重载
  cout << (str8 + str9) << endl;              //abddabdahservewpi

// ============================================迭代器
// //str9 abdahservewpi
  string::iterator ite;    // 指向string的指针 本质相当于char*
  // char *cp = str9.c_str;
  ite = str9.begin();      // 指向字符串的第一个元素
  for (size_t i = 0; i < str9.size(); i++)
  {
    cout << ite[i] << " ";                        //a b d a h s e r v e w p i
    cout << *ite << " ";
    ite++;
  }
  // ite = str9.begin();  
  // for (ite; ite != str9.end(); ite++)
  // {
  //   cout << *ite <<" ";                       //a b d a h s e r v e w p i
  // }

// // 迭代器修改值
    ite = str9.begin();
    for (ite; ite != str9.end(); ite++)
    {
      *ite = 'a';
      cout << *ite <<" ";                       //a a a a a a a a a a a a a
    }
    ite = str9.begin();
    ite[2] = 'd';
    cout << str9 << endl;                       //aadaaaaaaaaaa

// // 迭代器失效  当空间大小改变时 迭代器指向的原空间释放 数组申请新的连续的新空间 迭代器失效 要重新赋值begin()
    ite = str9.begin();
    str9.append(10,'b');
    cout << str9 <<endl;                        //aadaaaaaaaaaabbbbbbbbbb
    ite[1] = 'c';
    cout << str9 <<endl;                        //aadaaaaaaaaaabbbbbbbbbb 不变
// // 当不从新申请新空间时 没有问题
    string str10(7,'a');
    ite = str10.begin();
    str10.append(5,'b');
    ite[3] = 'c';
    cout << str10 <<endl;                              //aaacaaabbbbb

// // append (begin ,end)
    string str11("xbuvw");
    str11.append(str10.begin(), str10.begin()+5);
    cout << str11 <<endl;                              //xbuvwaaaca
// // erase 一个或一段 (index) (begin,end)
    str11.erase(str11.begin()+1);         //删除index=1的元素
    cout << str11 <<endl;                             //xuvwaaaca

// // insert 插入 (iterator,num, string)(iterator,str.begin(),str.end())
    str11.insert(str11.begin()+1, 3, 'y');
    cout << str11 << endl;                            //xyyyuvwaaaca

    string str12("nice");
    str11.insert(str11.begin()+1,str12.begin(), str12.end());
    cout << str11 << endl;                          // xniceyyyuvwaaaca

// ============================================算法

    FunForeach();

    // print

    // hiefaecgra
    // aaceefghir
    // 从大到小排序：
    // rihgfeecaa


  return 0;
}
