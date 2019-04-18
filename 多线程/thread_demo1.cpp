#include <iostream>
#include <thread>
#include <string>
using namespace std;
class A
// detach的一些注意点
{
public:
    mutable int at;
    A(int a):at(a){cout << "构造函数执行" << this << "thread ID: " << this_thread::get_id() << endl;}
    A(const A &a):at(a.at){cout << "拷贝构造函数执行" << this << "thread ID: " << this_thread::get_id() << endl;}
    ~A() {cout << "析构函数执行" << this << "thread ID: " << this_thread::get_id() << endl;} 
    void thread_work(int num)
    {
        cout << "**********************************" <<endl;
    }
};

class B
{
public:
    int at;
    B(int a):at(a){cout << "构造函数执行" << this << "thread ID: " << this_thread::get_id() << endl;}
    B(const B &a):at(a.at){cout << "拷贝构造函数执行" << this << "thread ID: " << this_thread::get_id() << endl;}
    ~B() {cout << "析构函数执行" << this << "thread ID: " << this_thread::get_id() << endl;} 
    void operator()(int num)
    {
        cout << "=======================================================" <<endl;
    }
};
void PrintDemo(const int& i, const string& pmystr)//char* pmybuf
{
    cout << i << endl;          //i不是mvar的引用 实际是值传入 主线程detach了子线程 二者无关系
    // cout << pmybuf << endl;         //指针在detech子线程中 有问题
    cout << pmystr.c_str() << endl; // 判断什么时候mybuf==>转成string 引用同样是复制的 调用了拷贝构造函数
    return ;
}

void PrintDemo1(const A& pmystr)
{
    cout << "子线程地址" << &pmystr << "  thread ID: " << this_thread::get_id() <<endl;  
}

void PrintDemo3(const A& pmystr)
{
    pmystr.at = 999;
    cout << "子线程地址" << &pmystr << "  thread ID: " << this_thread::get_id() <<endl;
}
void PrintDemo4(A& pmystr)
{
    pmystr.at = 999;
    cout << "子线程地址" << &pmystr << "  thread ID: " << this_thread::get_id() <<endl;
}

int main(void)
{
    int mvar = 1;
    int& mvary = mvar;
    char mybuf[] = "this is a test";
    int aa[] = {1,2,3,4,5,6};
    int bb = 99;
/////////////////////////////////////////////////////////////////////////////////////////
    // thread t1(PrintDemo, mvar, mybuf);  // 可以直接将mybuf转成string 如果转换的话 在主程序结束前转换传入子线程                                
    // t1.detach(); 
    /*
    传递int简单的类型参数 使用值传递
    传递类对象 避免隐式类型转换 全部都在创建线程这一行构建出临时对象 函数参数中 用引用来接 否则会构造三次(1次构造 2次拷贝构造)
    一般不使用detach() 只使用join()  不存在局部变量失效导致线程对内存的非法访问
    */
////////////////////////////////////////////////////////////////////////////////////////

    thread t2 (PrintDemo1,A(bb));// 临时对象 ==> 在main函数中
    t2.join();
    cout << "the end!!!!!!!!!!!!" << "主线程ID：" << this_thread::get_id() << endl;
    /*thread t2 (PrintDemo1,bb);
    构造函数执行0x70000f32fe78thread ID: 0x70000f330000
    子线程地址0x70000f32fe78  thread ID: 0x70000f330000
    析构函数执行0x70000f32fe78thread ID: 0x70000f330000
    the end!!!!!!!!!!!!主线程ID：0x1000b05c0
    */

    /*thread t2 (PrintDemo1,A(bb)); 在主线程中构造
    构造函数执行0x7ffeefbff378  thread ID: 0x1000b05c0
    拷贝构造函数执行0x7ffeefbff2a8  thread ID: 0x1000b05c0
    拷贝构造函数执行0x1002000a0     thread ID: 0x1000b05c0
    析构函数执行0x7ffeefbff2a8  thread ID: 0x1000b05c0
    析构函数执行0x7ffeefbff378  thread ID: 0x1000b05c0
    子线程地址0x1002000a0  thread ID: 0x70000a3aa000
    析构函数执行0x1002000a0thread ID: 0x70000a3aa000
    the end!!!!!!!!!!!!主线程ID：0x1000b05c0
    */
////////////////////////////////////////////////////////////////////////////////////////
    A a3(10);
    thread t3 (PrintDemo3,a3);//
    t3.join(); 
    cout << a3.at <<endl;  
    /*
    构造函数执行0x7ffeefbff358thread ID: 0x1000b65c0
    拷贝构造函数执行0x7ffeefbff258thread ID: 0x1000b65c0
    拷贝构造函数执行0x100300050thread ID: 0x1000b65c0
    析构函数执行0x7ffeefbff258thread ID: 0x1000b65c0
    子线程地址0x100300050  thread ID: 0x70000aa0f000
    析构函数执行0x100300050thread ID: 0x70000aa0f000
    10
    析构函数执行0x7ffeefbff358thread ID: 0x1000b65c0
    */
////////////////////////////////////////////////////////////////////////////////////////
// std::ref只是尝试模拟引用传递，并不能真正变成引用，在非模板情况下，std::ref无法实现引用传递，
// 只有模板自动推导类型时，ref能用包装类型reference_wrapper来代替原本会被识别的值类型，而reference_wrapper能隐式转换为被引用的值的引用类型。 
// ref()是利用模板参数推导实现的，如果你创建一个按值传参的非模板函数而想传递一个引用，ref()是做不到的。
// 在使用bind时，或者thread，需要用到ref() 必须外层用ref来进行引用传递，否则就是浅拷贝。

    A a4(10);
    thread t4 (PrintDemo4,ref(a4));// 加上ref 这样子线程就没有拷贝构造函数
    t4.join(); 
    cout << a4.at <<endl; 
    /*
    构造函数执行0x7ffeefbff348thread ID: 0x1000b65c0
    子线程地址0x7ffeefbff348  thread ID: 0x70000a98c000
    999
    析构函数执行0x7ffeefbff348thread ID: 0x1000b65c0
    */
////////////////////////////////////////////////////////////////////////////////////////
    A a5(10);
    thread t5(&A::thread_work,a5,66);// 函数地址 对象名 thread_work的变量
    t5.join(); 
    // 若使用ref  不会调用拷贝构造函数 同样 若对象为引用 传递的 &a5 也不会调用拷贝构造函数
    /* 
    构造函数执行0x7ffeefbff330 thread ID: 0x1000bb5c0
    拷贝构造函数执行0x7ffeefbff228 thread ID: 0x1000bb5c0
    拷贝构造函数执行0x100400058 thread ID: 0x1000bb5c0
    析构函数执行0x7ffeefbff228 thread ID: 0x1000bb5c0
    **********************************
    析构函数执行0x100400058 thread ID: 0x70000be73000
    析构函数执行0x7ffeefbff330 thread ID: 0x1000bb5c0
    */
////////////////////////////////////////////////////////////////////////////////////////

    B b1(10);
    thread tb1(b1, 88);  
    tb1.join();
    // 若使用ref  不会调用拷贝构造函数
    /*
    构造函数执行0x7ffeefbff310thread ID: 0x1000bf5c0
    拷贝构造函数执行0x7ffeefbff230thread ID: 0x1000bf5c0
    拷贝构造函数执行0x100300098thread ID: 0x1000bf5c0
    析构函数执行0x7ffeefbff230thread ID: 0x1000bf5c0
    =======================================================
    析构函数执行0x100300098thread ID: 0x70000c29c000
    析构函数执行0x7ffeefbff310thread ID: 0x1000bf5c0
    */

    return 0;
}
