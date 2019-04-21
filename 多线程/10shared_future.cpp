#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <list>
#include <mutex>
#include <future>
#include <vector>

using namespace std;

int ThreadPrint_PackedTask(int par)
{
    cout << "start!!!!!!!!" << "thread1 ID is: " << this_thread::get_id() << endl;
    chrono::milliseconds dura(5000); //定义5s时间
    this_thread::sleep_for(dura);  // 休息了一定时间
    cout << "end!!!!!!!!!!!" << "thread1 ID si: " << this_thread::get_id() << endl;
    return 5;
}

void ThreadPrint_PakcdeTask2(shared_future<int>& temp)
{
    // cout << par << endl;
    cout << "start!!!!!!!!" << "thread2 ID is: " << this_thread::get_id() << endl;
    auto result = temp.get(); //只能一次get 因为get函数设计语义 将temp中的值移动到result中
    cout << "the thread result is: " << result << endl;
    cout << "end!!!!!!!!!!!" << "thread2 ID is: " << this_thread::get_id() << endl;
}

int main(void)
{

    cout << "main" << "thread is : " << this_thread::get_id() << endl;
        
    packaged_task<int(int)> pt(ThreadPrint_PackedTask); // 通过函数将入口函数ThreadPrint_PackedTask包装起来
    thread t1(ref(pt),1); //线程直接开始执行 第二个参数作为线程的入口函数的参数
    t1.join();

    cout << "continue......!" << endl;
    future<int> result = pt.get_future(); 
        // future对象里面包含线程入口函数的返回结果 这里的result保存入口函数的返回结果
    
    bool ifcanget = result.valid();  //  true
    // shared_future<int> result_s(move(result)); // 将result里面的值过度到result_s 中去
    shared_future<int> result_s(result.share()); // 将result里面的值过度到result_s 中去 即result里面到值空了
        // shared_future<int> result_s = pt.get_future();  //可以不用future 直接用shared future
    ifcanget = result.valid(); //  false
    auto thread_result = result_s.get(); 
    auto thread_result1 = result_s.get(); // 可以多次get()


    thread t2(ThreadPrint_PakcdeTask2,ref(result_s));
    t2.join();

    cout << "***********************" << endl;

    return 0;

}