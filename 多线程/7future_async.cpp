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
    cout << "end!!!!!!!!!!!" << "thread ID si: " << this_thread::get_id() << endl;
    return 5;
}

class A
{
public:
    int ThreadPrint_Future(int par)
    {
        cout << par << endl;
        cout << "start!!!!!!!!" << "thread ID is: " << this_thread::get_id() << endl;
        chrono::milliseconds dura(6000); //定义5s时间
        this_thread::sleep_for(dura);  // 休息了一定时间
        cout << "end!!!!!!!!!!!" << "thread ID si: " << this_thread::get_id() << endl;
        return 6;
    }
};
int ThreadPrint_PackedTask(int par)
{
    cout << par << endl;
    cout << "start!!!!!!!!" << "thread ID is: " << this_thread::get_id() << endl;
    chrono::milliseconds dura(7000); //定义5s时间
    this_thread::sleep_for(dura);  // 休息了一定时间
    cout << "end!!!!!!!!!!!" << "thread ID si: " << this_thread::get_id() << endl;
    return 7;
}

vector <packaged_task<int(int)> > tasks; // 容器
int main(void)
{
    A a1;
    int temp = 12;
    cout << "main" << "thread is : " << this_thread::get_id() << endl;
    
    // future<int> result = async(ThreadPrint);
    
    // future<int> result = async(&A::ThreadPrint_A,&a1, temp);  // 第二个参数是对象引用 才能保证线程里面用的同一个对象
    
    // future<int> result = async(launch::deferred, &A::ThreadPrint_A, &a1, temp); 
        //launch::deferred 没有新线程被创建 直接在主函数中被创建的线程入口函数 在get() wait()的时候执行线程入口函数
    
    // future<int> result = async(launch::async, &A::ThreadPrint_Future, &a1, temp);  
        //launch::async在调用async 的时候开始创建线程     

    // packaged_task<int(int)> pt(ThreadPrint_PackedTask); // 通过函数将入口函数ThreadPrint_PackedTask包装起来
    // thread t1(ref(pt),1); //线程直接开始执行 第二个参数作为线程的入口函数的参数
    // t1.join();

    packaged_task<int(int)> pt1([](int par){
        cout << par << endl;
        cout << "start!!!!!!!!" << "thread ID is: " << this_thread::get_id() << endl;
        chrono::milliseconds dura(7000); //定义5s时间
        this_thread::sleep_for(dura);  // 休息了一定时间
        cout << "end!!!!!!!!!!!" << "thread ID si: " << this_thread::get_id() << endl;
        return 7;
    });
    thread t2(ref(pt1),2);
    t2.join();

    cout << "continue......!" << endl;
    int def;
    def = 0;

    // future<int> result = pt.get_future(); 
        // future对象里面包含线程入口函数的返回结果 这里的result保存入口函数的返回结果

    future<int> result = pt1.get_future(); 

    /*也可以直接函数调用
    pt1(100);
    future<int> result = pt1.get_future();
    cout << result.get() << endl;
    */
   /* 使用容器来调用
    tasks.push_back(move(pt1)); //入容器 移动语义 ===> pt1为空
    packaged_task <int(int)> pt2;
    auto ite = tasks.begin();
    pt2 = move(*ite);
    tasks.erase(ite); // 删除第一个元素 迭代器失效 不可以再使用ite
    pt2(222);
    future<int> result = pt2.get_future();
    cout << result.get() << endl;
    */


    // cout << result.get() << endl; // 如果没有get()拿到值 等待 卡在这里 直到get()拿到值
        // result.wait()  // ===> 等待线程返回 本身不返回任何结果;

    cout << "***********************" << endl;







    return 0;

}