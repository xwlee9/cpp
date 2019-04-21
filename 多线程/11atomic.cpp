#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <list>
#include <mutex>
#include <future>
#include <vector>
#include <atomic> 

using namespace std;

// int mycount = 0;

atomic<int> count1(0); // 封装了一个类型为int的对象值 我们可以想操作int类型的值一样来操作这个mycount
                // 复制初始化需要可访问的非显式复制或移动构造函数，因为它正式初始化来自相同类型的临时prvalue的变量。
                // 直接初始化不需要复制构造函数
// mutex mymutex;
void mythread()
{
    for (int i = 0; i < 1000000; i++)
    {
        // mymutex.lock();
        // mycount++;
        // mymutex.unlock();
        count1++; //对应的操作为原子操作(不会被打断)
        // 针对atomic 原子操作 针对++ -- += &= |= ^= 支持的 其他的可能不支持
    }
}
atomic<bool> ifend(false); 

void thread_ifend()
{
    chrono::seconds dura(1);
    while (ifend == false)
    {
        cout << this_thread::get_id() << "running" << endl;
        this_thread::sleep_for(dura);
    }
    cout << "thread id:" << this_thread::get_id() << "end!!!!!" << endl;
}
int main(void)
{
    cout << "main" << "thread is : " << this_thread::get_id() << endl;
    thread t1(mythread);
    thread t2(mythread);
    t1.join();
    t2.join();
    cout << count1 << endl;  // 多线程操作全局量 不安全 一条语句转成汇编语句可能有多条 会被打断

    // thread t3(thread_ifend);
    // thread t4(thread_ifend);
    // chrono::seconds dura(1);
    // this_thread::sleep_for(dura);
    // ifend = true;
    // t3.join();
    // t4.join();

    cout << "***********************" << endl;

    return 0;

}