#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <list>
#include <mutex>
#include <future>
#include <vector>

using namespace std;

void mythread(promise<int> &temp, int calc)
{
    ++calc;
    calc *= 10;

    chrono::milliseconds dura(5000);
    this_thread::sleep_for (dura);
    int result = calc;
    temp.set_value(result); // 结果保存到temp中
}

void mythread2(future<int> & temp)
{
    auto result = temp.get();
    cout << " thread2 result : " << result << endl;
}
int main()
{
    promise<int> prom; //声明一个std::promise 对象 prom ,保存的值类型为int
    thread t1(mythread, ref(prom), 100);
    t1.join();
    // 获取结果值
    future<int> val = prom.get_future(); //promis 和 future 绑定 用于获取线程的返回值
    // auto result  = val.get();
    // cout << "result : " << result << endl;

    thread t2(mythread2, ref(val));
    t2.join(); 
    cout << "===================================" << endl;


    return 0;
}