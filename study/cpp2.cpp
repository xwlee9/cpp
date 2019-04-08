#include <iostream>
using namespace std;

// 类：具有相同属性和行为的对象的集合 非静态
// 类是一种类型 只有在声明对象的时候才会分配空间 不可以直接在类内初始化是赋值
// C++中结构体是类一种特定的情况 结构体默认为public

// class Cpeople
// {
// private:
//   int c;
//
// public: //访问修饰符 类外可见
//   int a;
//   void fun()
//   {
//     cout << "fun" << " " << a << endl;
//   }
//
//   // 使用接口函数 获取 & 设置 私有
//   int Get()
//   {
//     return c;
//   }
//
//   void Set()
//   {
//     c = 123;
//   }


// private: //类内可见 默认为private
//   void fun_pv()
//   {
//     fun();
//   }
//   friend void fun_fr(); // 友元 类内成员对于这个函数相当于public 破坏类的封装性
//   friend class CXM; // 友元类
//
// protected: // 类内以及子类可见
//   void fun_pt()
//   {
//     fun();
//   }
//   friend void fun_fr(); // 保护也可以用友元
// };
//
// class CXM: public Cpeople
// {
// public:
//   void fun4()
//   {
//     fun();
//   }
// };
//
//
// void fun1()
// {
//   Cpeople op_f1;
//   op_f1.fun();
// }
//
// void fun_fr()
// {
//   Cpeople op_fr;
//   op_fr.fun_pv();
// }

//=============================================================构造函数
// class CStu_gouzao
// {
// public:
//   int age;
//   float score;
//   char gender;
//
//   // 构造函数 自动调用

// =========无参数的构造函数
//   CStu_gouzao() // 构造函数与类名一样 没有返回值
//   {
//     age = 18;
//     score = 99.9f;
//   }
//
// // =========有参数的构造函数
//   CStu_gouzao(int a, float b) // CStu_gouzao(int a, float b = 14.56f) //可以指定
//   {
//     age = a;
//     score = b;
//   }
//
//   CStu_gouzao(int a, char b = 'a'); // 类内声明
//
//   void fun() // 同样可以类内声明 类外定义
//   {
//     age = 18;
//     score = 99.9f;
//   }
//
// };
//
// CStu_gouzao::CStu_gouzao(int a, char b) // 类外定义
// {
//   age = a;
//   gender = b;
// }

//=============================================================初始化列表
// struct STU
// {
//   int h;
//   float k;
// };
//
// class CStu_chushihua
// {
// public:
//   int age;
//   // int &a;
//   float score;
//   char gender;
//   // const int b;
//   int b; //方便调试 替换const int b
//   int c[3];
//   STU st;
//   CStu_chushihua():age(19), score(99.6f), b(10){} //初始化列表 成员初始化顺序 只与声明的顺序有关 与初始化列表书写的顺序无关
//   CStu_chushihua(int d):age(d), score(99.6f),b(10){} //初始化
//   CStu_chushihua(int c, int d):age(c), b(d){}
//   // CStu_chushihua(int &c, int e):a(c), age(e){} // 不要用局部变量初始化a 局部变量在函数结束是被释放了 存在常量和引用 必须初始化
//
//   // CStu_chushihua()
//   // {
//   //   memset(c, 0, sizeof(c));
//   // }
//
//   CStu_chushihua(STU sh):st(sh){}
//
//
//
//   void Show()
//   {
//     cout << age << '\n' << score <<endl;
//     // cout << a ;
//   }
//   void Show_sz()
//   {
//     int i =0;
//     for (i = 0; i < 3; i++)
//     {
//       cout << c[i] <<endl;
//     }
//   }
//   void Show_st()
//   {
//     cout << st.h << '\n' << st.k << endl;
//   }
// };

//=============================================================析构函数
// class CStu_xigou
// {
// public:
//   int age;
//   int *p;
//   CStu_xigou()
//   {
//     // cout << "构造函数" << endl;
//     age = 12;
//     p = new int(10);
//   }
//   CStu_xigou(int i)
//   {
//     // cout << "构造函数" << endl;
//     age = i;
//     p = new int(10);
//   }
//   ~CStu_xigou() //析构函数 只有一个 没有参数 函数被系统回收前执行析构函数
//   {
//     // cout << "析构函数" << endl;
//     delete p; //析构函数释放p的空间
//   }
//
// };

//=============================================================this 指针
// class CStu_this
// {
// public:
//   int a;
//   CStu_this(int a)
//   {
//     this -> a = a; //区别局部变量
//     this ->Show();
//   }
//
//   void Show()
//   {
//     cout << a << '\n';
//   }
//
//   CStu_this* GetAddr()
//   {
//     return this;
//   }
// };

//=============================================================常函数
// // 构造函数 析构函数不可以是常函数
// // 不可以修改数据成员 可以使用数据成员 内部声明的变量可以修改 对函数有明确的限定

// class CStu_const
// {
// public:
//   int a;
//   CStu_const()
//   {
//     a = 12;
//   }
//   void Show() const // this指针是const CStu_const*
//   {
//     int b = 2;
//     b = b*a;
//     cout << b << endl;
//   }
// };

//=============================================================静态成员
// // 类创建的时候就有静态成员
// class CStu_static
// {
// public:
//   static int a; //类外初始化 无this指针 属于类的属性 不是对象 可通过类名或对象调用
//   static const int b =16; //只有静态常量整型数据成员可以进行初始化
//   int c; // 对象创建的时候 静态成员存在 而c不存在
//   static int d;
//
//   CStu_static()
//   {
//     d++;
//     a = 12;
//   }
//
//   static void  Show() //
//   {
//     cout << a << endl;
//     // c = 9; 只能使用静态成员
//   }
//
// };
// int CStu_static::a = 13; //无static
// int CStu_static::d = 0; //

//=============================================================拷贝构造
// //默认的复制构造函数 是逐个复制非静态成员（浅复制），复制成员值
// class CStu_copy
// {
// public:
//   int a;
//   char c[4];
//   CStu_copy()
//   {
//     a = 12;
//     // c[0] = 'a';
//     strcpy(c,"abc");
//   }
//   // CStu_copy(const CStu_copy&a) //拷贝构造  默认的是有内容
//   // {
//   //
//   // }
// };
//
// void fun_cp(CStu_copy a)
// {
//
// }
//
// CStu_copy fun_cp()
// {
//   CStu_copy a;
//   return a;  // 调用拷贝构造 返回临时对象 用a来初始化
// }


//=============================================================深拷贝

// class CStu_deepcopy
// {
// public:
//   int *a; // 指向一个地址 浅拷贝时候 指向同一个空间
//
//   CStu_deepcopy()
//   {
//     a = new int[2];
//     a[0] = 22;
//     a[1] = 33;
//   }
//
//   CStu_deepcopy(const CStu_deepcopy &b)
//   {
//     this -> a = new int[2]; //从新申请空间 避免重复释放
//     // this -> a[0] = b.a[0];
//     // this -> a[1] = b.a[1];
//     memcpy(this->a, b.a, 8); //拷贝内存 (dst, src, 字节数)
//     // //memcpy函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dst所指的内存地址的起始位置中。
//   }
//
//   ~CStu_deepcopy()
//   {
//     delete[] a;
//   }
// };
//
// CStu_deepcopy& fun_yy(CStu_deepcopy &a) //传递引用
// {
//   return a;
// }
//
// CStu_deepcopy* fun_zz(CStu_deepcopy *a) //传递引用
// {
//   return a;
// }

//=============================================================内联函数
// //用相应代码替换调用 快 但占用内存
// //部分编译器： 函数体过大 递归不是内联函数
// //类内是内联函数

// inline void fun1(int i)
// {
//   cout << (i*i);
// }
//
// class CStu_neilian
// {
//   void fun2()
//   {
//
//   }
//   void fun3();
//
// };
//
// inline void CStu_neilian::fun3() //定义在类外 没有inline不是内联函数
// {
//   }




int main()
{
//   Cpeople op;
//   op.a =12;
//   op.fun(); //栈区用.
// // ==========堆区类
//   Cpeople *op1 = new Cpeople;
//   op1 -> a = 13;
//   op1 -> fun(); //堆区用->
//   delete op1;
//
// // ==========子类
//   CXM xm;
//   xm.a = 15;
//   xm.fun4();
// // ==========友元
//   fun_fr();
// // ==========接口函数
//   op.Set();
//   int a = op.Get();
//   cout << a << endl;

//=============================================================构造函数

// // 给数据成员赋值  //对象创建的时候调用 允许重载
// // =========无参数的构造函数
//   CStu_gouzao csgz;
//   cout << csgz.age << '\n' << csgz.score << endl;
//
//   CStu_gouzao *csgz1 = new CStu_gouzao; // 在new空间的时候才会创建对象 否则不会调用构建函数
//   cout << csgz1->age << '\n' << csgz1->score << endl;
//
// // =========有参数的构造函数
//   CStu_gouzao csgz2(12,12.4f);
//   cout << csgz2.age << '\n' << csgz2.score << endl;
//
//   CStu_gouzao *csgz3 = new CStu_gouzao(35,54.7f); // 在new空间的时候才会创建对象 否则不会调用构建函数
//   cout << csgz3->age << '\n' << csgz3->score << endl;

//=============================================================初始化列表
  // CStu_chushihua cscsh;
  // CStu_chushihua cscsh1(11);
  // cscsh.Show();
  // cscsh1.Show();

// ==========引用
  // int d = 12;
  // CStu_chushihua cscsh2(d, 15);
  // cscsh2.Show();

// ==========数组
  // CStu_chushihua cscsh;
  // cscsh.Show_sz();
// ==========结构体初始化
  // STU sf = {123, 123.4f};
  // CStu_chushihua cscsh3(sf);
  // cscsh3.Show_st();

//=============================================================析构函数
  //
  // CStu_xigou* csxg = new CStu_xigou;  // 析构函数在结束标志的时候调用  return } delete
  // delete csxg;
  //
  // CStu_xigou(12); // 临时对象          CStu_xigou csxg(12)
  //
  // //new 会触发构造函数       malloc  不会触发构造函数
  // //delet 会触发析构函数     free 不会触发析构函数


//=============================================================this 指针
// //对象创建的时候才有 对应对象的类的指针 不是成员 是类成员函数的隐藏参数 作用域在类内部 默认传递给函数的隐藏参数

    // CStu_this cst(12);
    // cst.Show();
    //
    // CStu_this cst1(13);
    // cst1.Show();
    //
    // CStu_this *p = cst.GetAddr();
    // cout << p << endl;

//=============================================================常函数
// //常对象只能调用常函数
    // const CStu_const csc;
    // csc.Show();

//=============================================================静态成员

    // cout << CStu_static::a << endl; //类名作用域 13
    //
    // CStu_static css;
    // cout << css.a << endl; // 对象 12
    // css.Show();
    // CStu_static css1[5];
    //
    // cout << CStu_static::d << endl; //1+5 = 6 静态成员

//=============================================================拷贝构造
    //
    // CStu_copy cscp;
    // //几种初始化同类现有对象方法
    // CStu_copy cscp1(cscp);
    // CStu_copy cscp2 = cscp;
    // CStu_copy cscp3 =CStu_copy(cscp); //不多见
    // CStu_copy* cscp4 = new CStu_copy(cscp);
    //
    // cout << cscp.a << " " << cscp.c <<endl;
    // cout << cscp1.a << " " << cscp1.c <<endl;
    // cout << cscp2.a << " " << cscp2.c <<endl;
    // // fun_cp(cscp); //函数也可以
    // // fun_cp();

//=============================================================深拷贝
    //
    // CStu_deepcopy csdcp;
    // cout << csdcp.a[0] << " " << csdcp.a[1] << endl;
    //
    // // 浅拷贝在复制构建的时候 重复释放空间 1深拷贝 2传地址 3传引用
    // CStu_deepcopy csdcp1 = csdcp;   // 此时不执行构造函数 执行拷贝构造 默认不申请空间
    // cout << csdcp1.a[0] << " " << csdcp1.a[1] << endl;
    //
    // // funyy(csdcp);  //传引用
    // // funzz(&csdcp); //传地址 指针

//=============================================================内联函数
// //比宏更智能
  // fun1(2+3);






  return 0;
}
