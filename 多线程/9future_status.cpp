#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <list>
#include <mutex>
#include <future>
#include <vector>

using namespace std;

int ThreadPrint()
{
    // cout << par << endl;
    cout << "start!!!!!!!!" << "thread ID is: " << this_thread::get_id() << endl;
    chrono::milliseconds dura(5000); //定义5s时间
    this_thread::sleep_for(dura);  // 休息了一定时间
    cout << "end!!!!!!!!!!!" << "thread ID is: " << this_thread::get_id() << endl;
    return 5;
}


int main(void)
{

    cout << "main" << "thread is : " << this_thread::get_id() << endl;

    future<int> result = async(ThreadPrint);
    // future<int> result = async(launch::deferred,ThreadPrint);

    cout << "continue......!" << endl;  
    // cout << result.get() << endl; 
    //     // future对象里面包含线程入口函数的返回结果 这里的result保存入口函数的返回结果

    future_status status = result.wait_for(chrono::seconds(6)); //等待1s 等待一定的是时间
        // wait_for(5ms) wait_for(10s) wait_for(5min)
    if (status == future_status::timeout) // 线程没有执行完 等待时间1s 而线程没有返回 那么状态就等于 status=timeout
    {
        cout << "timeout!!! 线程没有执行完!!!" << endl;
    }
    else if (status == future_status::ready)
    {
        cout << "ready!!! 线程成功返回!!!" << endl;
        cout << result.get() << endl;
    }
    else if (status == future_status::deferred)
    {
        // 如果async的第一个参数 被设置为 launch::deferred 则本条件成立 只有调用get()才执行 否则不执行 
        cout << "线程延迟执行" << endl;
        cout << result.get() << endl;  // 在主线程中调用的 也就不会在wait for中等待

    }
    cout << "***********************" << endl;

    return 0;

}