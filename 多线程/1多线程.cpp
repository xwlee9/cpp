#include <iostream>
#include <thread>

using namespace std;

class TH
{
public:
  int &mi;
  TH(int& i):mi(i)
  {
    cout << "构造函数执行" << endl;
  }
  TH(const TH& th):mi(th.mi)
  {
    cout << "拷贝构造函数执行" << endl;
  }
  ~TH()
  {
    cout << "析构函数执行" << endl;
  }
  void operator()() // 重载
  {
    cout << "my operator is running" << endl;
    cout << "my operator has finished" << endl;
    cout << "************************" <<endl;
  }
};

void MyPrint()
{
  cout << "线程开始执行！" << endl;
  cout << "线程结束执行！" << endl;
}

int main(void)
{
  // cout << "NICE" << endl; // 主线程执行 主线程从main()函数返回 整个进程执行完毕

  // // 创建的线程 也需要从一个函数开始运行 函数运行结束 线程运行结束
  // // 主线程执行完毕 === >  进行执行完毕 若其他子线程未执行完毕 一般情况下这些子线程被操作系统强行中止
  // // 保持子线程运行状态 让主线程的运行
  // // thread 标准库中的类 MyPrint 可调用对象
  // thread MyObj(MyPrint); // 创建了线程 线程开始执行
  // // MyObj.join(); // 阻塞主线程 等待子线程执行完毕
  // if (MyObj.joinable())
  // {
  //   MyObj.detach(); // 子线程和主线程分离
  //
  //   cout << "主线程结束" << endl;
  // }
  // int i = 99;
  // TH th(i);
  // thread MyObj1(th);
  // MyObj1.join();
  // MyObj1.detach();

  auto mylamthread = [] {
    cout << "线程开始执行" << endl;
    cout << "线程结束执行" << endl;
  };
  thread Myobj2(mylamthread);
  Myobj2.join();

  cout << "主线程结束" << endl;

  return 0;

}
