#include <iostream>
using namespace std;

struct Node
{
  int a;
  void fun() // cpp中结构体中可以放函数
  {
    cout << "hello" << '\n';
  }
};
//=============================================================
void fun1(int &a8)  //a8是引用
{
  a8 = 16;
  cout << a8 << endl;
}

void fun2(int a8)  // 此时a8是自己单独的一块空间
{
  a8 = 18;
  cout << a8 << endl;
}

void fun3(int* a8)  // 此时a8是自己单独的一块空间
{
  *a8 = 19;
  cout << *a8 << endl;
}

//==============================================================
void Exchange(int a, int b)
{
   int temp = a;
   a = b;
   b =temp;
}

void Exchange1(int &a, int &b)
{
   int temp = a;
   a = b;
   b =temp;
}

//==============================================================

int& fun4(int a = 1, int b=2)
{
  a = a + 1;
  return a;
}


//=============================================================函数的重载
void Show(char c)
{
  cout << c <<endl;
}

void Show(int a)
{
  cout << a <<endl;
}

void Show(double b)
{
  cout << b <<endl;
}

//=============================================================


int main(void)
{
  //====================================结构体
  // Node node; //可以不用struct
  // node.fun();
  //====================================空间申请释放
  // //可以使用malloc & free 但是 new delete 可以出发构建和析构
  // int *pn1 = new int; // 申请空间 new type
  // *pn1 = 12;
  // int *pn2 = new int(121); //初始化
  // int *pn3 = new int[6]; //数组 空间
  // pn3[0] = 30;
  // pn3[1] = 31;
  // pn3[2] = 32;
  // pn3[3] = 33;
  // int *pn4 = new int[6];
  // memset(pn4, 0, 5*4);
  // cout << *pn1 << '\n';
  // cout << *pn2 << '\n';
  // cout << pn3[0] << " " << pn3[1] << " " << pn3[2] << " " << '\n';
  // cout << pn4[0] << " " << pn4[1] << " " << pn4[2] << " " << '\n';
  // delete pn1; // 空间释放
  // delete pn2;
  // delete[] pn3; // 数组 []
  // delete[] pn4;
  //====================================引用
  // //变量起别名 声明的时候就要初始化 不可以更改
  // int a1 = 11;
  // int &b1 = a1; //声明变量a1的一个引用b1 是a1的别名    a1 b1指向同一个空间
  // int &b2 = b1;
  // cout << &a1 << " " << &b1 << " " << &b2 << " " << '\n';
  // cout << a1 << " " << b1 << " " << b2 << " " << '\n';
  // b1 = 12;
  // cout << a1 << " " << b1 << " " << b2 << " " << '\n';
  // // 常量
  // const int &a3 = 33;
  // cout << a3 << '\n';
  // // 数组
  // int a4[12];
  // int (&b4)[12] = a4;
  // b4[2] = 44;
  // cout << a4[2] << '\n';
  //
  // int a5[2][3];
  // int (&b5)[2][3] = a5;
  // b5[1][1] = 55;
  // cout << a5[1][1] << '\n';
  //
  // // 指针
  // int a6 = 66;
  // int *b6 = &a6;
  // int *(&b7) = b6;
  // *b7 = 77;
  // cout << *b7 << " " << *b6 << " " << a6 << '\n';
  //
  // //
  // int b8 = 88;
  // fun1(b8);  // 此时b8改变
  // cout << b8 << endl;
  // fun2(b8);  // 此时b8不能改变
  // cout << b8 << endl;
  // fun3(&b8); // 传指针
  // cout << b8 << endl;

  // int a9 = 11;
  // int b9 = 22;
  // cout << a9 << " " << b9 << endl;
  // Exchange(a9, b9);
  // cout << a9 << " " << b9 << endl;
  // Exchange1(a9, b9);
  // cout << a9 << " " << b9 << endl;


  int ax = 33;
  //int &bx = fun4(ax); // wrong 不要引用局部变量
  // https://blog.csdn.net/tlxxm/article/details/8860760


  //===================
  // 函数指定默认值 部分指定 从右往左指定
  // 有默认值的参数 不用 传递参数 没有默认值的参数必须传递实参
  // 有默认值传递实参 会覆盖

  //=============================================================函数的重载
  // //允许函数名相同 但形参不一样就会不同  在公共作用域内允许重载 返回值不作为重载的条件
  // //注意浮点数 float 加f后缀 区分和double
  // Show('a');
  // Show(11);
  // Show(12.34f);


  /*默认函数和重载结合使用 可能会造成调用不明确
  void Show(int a)
  {
    cout << a <<endl;
  }

  void Show(int a, int b =0)
  {
    cout << a << " " << b << endl;
  }
  Show(11); // 调用不明确
  */


  //=============================================================预处理
  /*头文件预处理
  #ifndef aaa
  #define aaa

  #endif
  //======

  #pragma once //取决于编译器
  */

  return 0;
}
