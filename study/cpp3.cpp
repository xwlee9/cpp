#include <iostream>
using namespace std;

//=====================================================================运算符重载
// class Cpeople
// {
// public:
//   int age;
//   float score;
//
//   Cpeople()
//   {
//     age = 12;
//     score = 99.9f;
//   }
//
//   int operator-(int a) //this 类 +a 运算符重载 定义在类内
//   {
//     return (this->age - a);
//   }
//
// };
//
// void operator+(Cpeople&cp, int a)
// {
//   cout << (cp.age + a) << endl;
// }
//
// int operator+(int a, Cpeople&cp)
// {
//   return (cp.age + a);
// }
//
// Cpeople& operator+(Cpeople&cp1, Cpeople&cp)
// {
//   cp1.age += cp.age;
//   return cp1;
// }


//=====================================================================运算符重载
// class Com
// {
// private:
//   int a;
//   double b;
//   friend ostream& operator <<(ostream& os, const Com& cm);
//   friend istream& operator >>(istream &ist, Com& cm);
//   friend int operator ++(Com& cm, int n);
// public:
//   Com()
//   {
//     a = 12;
//     b = 2.7;
//   }
//
//   operator int() //无显示返回类型 要写返回值 没有参数 必须定义类内成员 不改变对象内容
//   {
//     return a;
//   }
//   operator double() const
//   {
//     return b;
//   }
//
//   void Show()
//   {
//     cout << b << endl;
//   }
// };
//
// // void operator <<(ostream& os, const Com& cm)  //无修改 用const ostream 引用
// // {
// //   os << cm.a;
// // }
//
//
// ostream& operator <<(ostream& os, const Com& cm)
// {
//   os << cm.a;
//   return os;
// }
//
// istream& operator >>(istream &ist, Com& cm)
// {
//   ist >> cm.b;
//   if(ist.fail())
//   {
//     cout << "fail" << endl;
//   }
//   return ist;
// }
//
// int operator ++(Com& cm, int n) //n可以理解成后置++的一个标记
// {
//   n = cm.a;
//   cm.a += 1;
//   return n;
// }

//=====================================================================继承
// // public  父类怎样 子类怎样
// // protected  继承之后 父类public降级成 protected 父类中 protected private 不变
//
// class Cpeople //基类 父类
// {
// private:
//   void fun1()
//   {
//     cout << "father functions" << endl;
//   }
// protected:
//   void fun2()
//   {
//     cout << "father protected" << endl;
//   }
// public:
//   int a;
//   Cpeople()
//   {
//     cout << "Cpeople" << endl;
//   }
//   ~Cpeople()
//   {
//     cout << "~Cpeople" << endl;
//   }
//   void Study()
//   {
//     cout << "study" <<endl;
//   }
// };
// // // ======================继承限定词 test
// // // public  父类怎样 子类怎样
// // // protected  继承之后 父类public降级成 protected 父类中 protected private 不变
// // // private 继承之后 父类的成员全部变成私有成员
//
// class Cchild : public Cpeople //派生类 子类
// {
// public:
//   Cchild()
//   {
//     cout << "child" <<endl;
//     fun2();
//   }
//   ~Cchild()
//   {
//     cout << "~child" <<endl;
//   }
//   void go2school()
//   {
//     cout << "go to school" <<endl;
//
//   }
// };
//
// class XiaoMing : public Cchild
// {
// public:
//   XiaoMing()
//   {
//     cout << "xiaoming" <<endl;
//   }
//   ~XiaoMing()
//   {
//     cout << "~xiaoming" <<endl;
//   }
// };
//
// // //======================构造函数 参数传入test
// class Cman : public Cpeople
// {
// public:
//   Cman(int a)
//   {
//     cout << "this is man" << endl;
//   }
//   void Work()
//   {
//     cout << "go to work" <<endl;
//   }
// };
//
// class Jack : public Cman
// {
// public:
//   Jack():Cman(1) //在构建函中 父类如果有参数 子类也要传入值
//   {
//   }
// };
//
// // //======================构造函数 参数传入test
//
//
// class Coldman : public Cpeople
// {
// public:
//   int a;
//   Coldman()
//   {
//     a = 22;
//   }
//   void Park()
//   {
//     cout << "go to park" <<endl;
//   }
// };
//
// // //子父类数据成员重名 子类会覆盖父类 可以用类名作用域来区分 函数相同 不是重载关系依旧用类名作用域区别
// // //友元不可以继承
// class LiBai : public Coldman
// {
// public:
//   int a;
//   LiBai()
//   {
//     a = 11;
//   }
//   void fun_lb()
//   {
//     cout << a << endl;
//   }
//   void fun_lb_f()
//   {
//     cout << Coldman::a << endl;
//   }
//
// };

//=====================================================================多态与虚函数
// //多态 同样的代码实现不同的功能 父类的指针调用子类的空间
// //虚是针对的函数成员 名字参数相同 返回值相同 当返回值不同时  协变   return(*this) 返回当前类的引用 指针
// //虚函数 不可以是 内敛函数 构造函数      虚表 覆盖
// //虚析构 析构函数前加virtual 这样可以同时调用子类父类的析构函数
// //纯虚函数
// class CFather
// {
// public:
//   int a0;
//   virtual void show() // 若存在virtual 父类调用的是子类的同名函数 否则调用自己的
//   {
//     cout << "this is father" << endl;
//   }
//
//   virtual ~CFather() // 虚析构
//   {
//     cout << "fatehr" << endl;
//   }
//
// };
//
// class CSon : public CFather
// {
// public:
//   int a1;
//   void show()  // 父类同名函数有virtual 子类有隐性virtual
//   {
//     cout << "this is son" <<endl;
//   }
//   ~CSon()
//   {
//     cout << "son" <<endl;
//   }
// };
//
// class CSon1 : public CFather
// {
// public:
//   int a2;
//   void show()
//   {
//     cout << "this is son1" <<endl;
//   }
// };
//
// class CGrandSon : public CSon
// {
// public:
//   int a3;
//   void show()
//   {
//     cout << "this is grandson" <<endl;
//   }
// };


//=====================================================================纯虚函数
// //纯虚函数的类必须子类重写该虚函数 才能实例化对象
// //类内全部纯虚函数 为接口类
// class Animal
// {
// public:
//   virtual void fun() = 0; // 纯虚函数
// };
//
// class Cat : public Animal
// {
// public:
//   void fun()
//   {
//     cout << "纯虚函数" << endl;
//   }
// };

//=====================================================================虚继承
// // 虚继承 继承父类中成员的使用 但成员不属于子类 解决继承中访问不明确的问题
// class CA
// {
// public:
//   int a;
//   CA()
//   {
//     a = 11;
//   }
// };
//
// class CB : virtual public CA
// {
// public:
//   // int a;
// };
//
// class CC : virtual public CA
// {
// public:
//   // int a;
// };
//
//
// class CD : public CB, public CC
// {
// public:
//   // int a;
// };

//==========================================================================
//==========================================================================
//==========================================================================

int main()
{


//=====================================================================运算符重载
// //必须重载有效的运算符
// // = [] () -> -= += *= /= ++ 成员   void *通用类型指针
  // int a;
  // Cpeople cp1,
  //         cp2;
  // cp1 + 12;
  //
  // a = 13 + cp2;
  // cout << a <<endl;
  //
  // cp1 + (15 + cp2 + 100);
  //
  // cout << 15 + (cp1 + cp2) <<endl;
  //
  // cout << cp2 - 15 << endl; //12-15

//=====================================================================运算符重载
  // Com cm1;
  // // cout << cm1;
  // cout << cm1 << cm1;

  // Com cm2;
  // cin >> cm2;
  // cm2.Show();

  // Com cm3;
  // cout << (cm3++);
  // cout << cm3;
  //
  // Com cm4;
  // cout << (int)cm4;
  // cout << (double)cm4;



//=====================================================================继承
  // Cchild child;
  // child.Study();
  // // child.fun2();
  //
  // Cchild* child1 = new Cchild;
  // child1 -> Study();
  //
  // delete child1;

  // //===========================

  // XiaoMing xm;
  // Jack jc;
  // 构造函数 先父类后子类 析构函数 先子类后父类

  // //=================result
  // // Cpeople            // Cpeople 构造函数 cout
  // // child              // Cchild 构造函数 cout
  // // father protected   // Cchild 构造函数 fun2()
  // // xiaoming           //XiaoMing 构造函数cout
  // // Cpeople            //Jack | Cpeople 构造函数 cout
  // // this is man        //Jack | Cman 构造函数 cout
  // // ~Cpeople           //Jack | Cpeople 析构函数 cout
  // // ~xiaoming          //XiaoMing 析构函数cout
  // // ~child             //Cchild 析构函数 cout
  // // ~Cpeople           //Cpeople 析构函数 cout

  // //==========================
  // LiBai lb;
  // lb.fun_lb();
  // lb.fun_lb_f();
  // cout << lb.Coldman::a<<endl;


//=====================================================================多态 虚函数
// // 多态 父类的指针 可以指向多种状态
//   CFather* cf = new CSon;
//   cf -> show();
//
//   CFather* cf1 = new CSon1;
//   cf1 -> show();
//
//   CSon* cs = new CGrandSon;
//   cs -> show();
//
//
//   // typedef void (*p)();
//   // ((p)(*((int*)(*(int*)cf))))();
//   // // 虚表      对象空间开始的四个字节内容 就是虚表的地址
//   // // *((int*)(*(int*)cf))   *((int*)(*(int*)cf) + 1) 虚表结尾 0x00000000
//   // // (int*)cf 对象首地址转int*
//   // // *(int*)cf  首地址装的 show() 地址
//   // // (int*)(*(int*)cf) 将show()地址强转 int*
//   // // *((int*)(*(int*)cf))  取show()内容
//
//   delete cf;
//   delete cf1;
//   // delete (CSon1*)cf; //delete 区别类型调用Cson1 的析构函数
//=====================================================================纯虚函数
    // Cat cat;
    // cat.fun();

//=====================================================================多继承
  // CD cd;
  // cout << cd.a << endl;

  return 0;

}
