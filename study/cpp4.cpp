#include <iostream>
using namespace std;

// class CA
// {
// public:
//   virtual void fun()
//   {
//     cout << "CA" << endl;
//   }
// };
//
// class CB : public CA
// {
// public:
//   void fun()
//   {
//     cout << "CB" << endl;
//   }
// };

//==============================================================================单例
// class CFather
// {
// private:
//   CFather()
//   {
//   }
// public:
//   static int nFflag;
//
//   static CFather* CreateOJ()
//   {
//     if (1==nFflag)
//     {
//       nFflag =0;
//       return (new CFather);
//     }
//     else
//     {
//       return NULL;
//
//     }
//   }
//   ~CFather()
//   {
//     nFflag = 1;
//   }
// };
// int CFather::nFflag = 1;
//==============================================================================异常
// void fun(int a)
// {
//   if (0 == a)
//   {
//     abort(); //异常中止
//   }
//   cout << a << endl;
// }
//
//
// void fun1(int a)
// {
//   while (a < 10)
//   {
//     if (5 == a)
//     {
//       throw a; // 抛出变量a
//     }
//     cout << a << endl;
//     a++;
//
//   }
//
// }
//
// // ===============类
// class Cpeople
// {
// public:
//   int b;
//   Cpeople()
//   {
//     b = 12;
//   }
// };
//
// void fun_cf(Cpeople &c)
// {
//   while (c.b < 20)
//   {
//     if (15 == c.b)
//     {
//       throw &c;
//     }
//     c.b++;
//   }
// }
//==============================================================================内部类
// class OUT
// {
// public:
//   int a;
//   OUT()
//   {
//     a = 11;
//   }

// public:
//   class IN
//   {
//   public:
//     int b;
//     IN()
//     {
//       b = 22;
//     }
//     void fun_in()
//     {
//       OUT ou;
//       cout << ou.a << endl;
//     }
//   };
// public:
// IN in;
// };

// // ==================可以改变参数值
// class OUT
// {
// public:
// int a;
// OUT():in1(this) //利用this指针将参数传入内部类
// {
//   a = 11;
// }
// public:
//   class IN1
//   {
//   public:
//     int c;
//     OUT *p;
//     IN1(OUT *pf):p(pf) //用pf给p初始化
//     {
//       c = 33;
//     }
//     void fun_in1()
//     {
//       cout << p -> a << endl;
//     }
//   };
//
//   IN1 in1;
// };
//==============================================================================类型转换
// class Father
// {
//   int a;
// };
//
// class Son : public Father
// {
//   int a;
// };
//==============================================================================函数模版
// template<typename T> // ==  template<class T>        template<typename T, typename Y> 仅对接下代码段有效
// void  fun_t(T a)
// {
//   cout << a << endl;
// }
//
// struct Node
// {
//   int a;
//   double b;
// };
//
// template<> void fun_t1 <Node>(Node& no) // xcode ？？
// {
//   cout << no.a << " " << no.b << endl;
// }
// // template<> void fun<job>(job&j1, job&j2); // 将指定的类型单独处理
//==============================================================================类模版
// template <typename T>  //template <typename T = char>  类模板才有默认值   BA<> ba
// class BA
// {
// public:
//   T a;
//   BA(T t)
//   {
//     a = t;
//   }
//   void Show()
//   {
//     cout << a << endl;
//   }
//   void Show1();
// };
//
// template <typename T>
// void BA<T>::Show1()
// {
//   cout << a << endl;
// }

//==============================================================================类模版
// template <typename T>
// class CA
// {
// public:
//   T a;
//   CA()
//   {
//     a = 12;
//   }
//   virtual void Show()
//   {
//     cout << a << endl;
//   }
// };
// template <typename X>
// class CB : public CA<X>
// {
// public:
//   CB()  // :CA<X>()
//   {
//   }
//   virtual void Show()
//   {
//     cout << "cb" << endl;
//   }
// };





int main()
{
  // // =========
  // CA a;
  // a.fun();
  //
  // CA* a = new CB;
  // a -> fun();

  // // =========动态联编 程序执行的过程中才将函数实现与函数调用关联 针对多态
  // CA* a;
  // int b;
  // cin >> b;
  // switch (b) {
  //   case 1: a = new CA; break;
  //   case 2: a = new CB; break;
  // }
  // a -> fun();

//==============================================================================单例
// // 构建函数 不能实例化对象 private protected 若private 不能继承 运行报错
// // 通过静态成员函数申请对象空间 返回地址
// // 定以静态标记 记录对象个数 并且控制
// // 析构函数 清空标记 达到重复申请的目的
//     CFather* cf = CFather::CreateOJ();
//     delete cf;
//
//     CFather* cf1 = CFather::CreateOJ();
//     delete cf1;

//==============================================================================异常
  // fun(0);
//   try
//   {
//     fun1(2);
//   }
//   catch(int b) //
//   {
//     cout << b << endl;
//     try   // 处理异常
//     {
//       fun1(b+1);
//     }
//     catch(int d)
//     {
//
//     }
//   }
//
//   catch(char c) // 可以  重载
//   {
//     cout << c << endl;
//   }
//
//   catch(...)  // 其他处理
//   {
//     cout << "default" <<endl;
//   }
//
//
// //  // ================== 类
//   Cpeople cp;
//   try
//   {
//     fun_cf(cp);
//   }
//   catch(Cpeople& a)
//   {
//
//   }
//
//   catch(Cpeople* a)
//   {
//     a -> b++;
//   }

//==============================================================================内部类
  // OUT oi;
  // oi.a = 99;  // 复制给oi对象里的a 而ou对象里的a 不变
  // // oi.in.fun_in(); // 11
  // oi.in1.fun_in1(); // 11

//==============================================================================类型转换
  //
  // Father *f;
  // Son *s;
  // // f = (Father*)s;
  // f = static_cast<Father*>(s); //type 与 expression可以互相隐式转换 基类子类可以互相转换 与不相管的不能转换
  //
  //
  // const Father* f1;
  // Son* s1;
  // Father* f2 = const_cast<Father*>(f1);  // typed expression 转换掉表达式中的const 或 volatile属性
  //
  // f = dynamic_cast<Father*>(s);
  // // s = dynamic_cast<Father*>(f); // 有继承关系的转换 基类子类转转  多态情况可以父类转子类
  //
  // struct dat
  // {
  //   short a;
  //   short b;
  // };
  // long value = 0xA234567F;
  // dat *p = reinterpret_cast<dat*>(&value);
  // cout << hex << p->a << p->b <<endl;

  // hex表示之后的数字以16进制方式输出
  // oct表示之后的数字以8进制方式输出
  // dec表示之后的数字以10进制方式输出

//==============================================================================函数模版

  // fun_t("hello");
  // fun_t(12.3);
  //
  // Node no = {12, 12.3};
  // fun_t1<Node>(no);
// //==============================================================================类模版
//   BA<char> ba('a'); //模版参数列表
//   ba.Show();
//
//   BA<char>* ba1 = new BA<char>('b'); //类之外，任何地方出现类名都要加上模版列表
//   ba1 -> Show();
//
//   ba.Show1();
//   ba1 -> Show1();
// //==============================================================================类模版
// //模板的也可以是类

  // CB<int> cb;
  // cb.Show();
  //
  // CA<int>* ca = new CB<int>;
  // ca -> Show();





  return 0;
}
