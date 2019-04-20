#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>

using namespace std;
////////////////////////////////////////////一把锁
class A
{
public:
    void inMsgRecvQueue() // 收到的消息入到队列的栈中
    {
        for (int i = 0; i < 10000; ++i)
        {
            cout << "hello" << i << endl;
            my_mutex.lock();
            msgRecvQueue.push_back(i);  // 假设数字i为收到的命令 入队列 
            my_mutex.unlock();
        }
    }
    bool outMsgProc(int& command)
    {
        lock_guard<mutex> lck(my_mutex);  // lck对象名 构造函数里执行lock() 析构函数里执行unlock()
        // my_mutex.lock();
        if (!msgRecvQueue.empty())
            {
                command = msgRecvQueue.front();
                msgRecvQueue.pop_front();
                // my_mutex.unlock();
                return true;
            }
        // my_mutex.unlock();
        return false;

    }
    void outMsgRecvQueue()
    {
        int command = 0;
     
        for (int i = 0; i < 10000; ++i)
        { 
            bool result = outMsgProc(command);
            if (result == true)   cout << "取出命令: " << command << endl;
            else  cout<< "the outMsgRecvQueue is empty!" <<endl;
        }
        cout << "end!!!!!!!!!!!" <<endl;
    }


private:
    list<int> msgRecvQueue;
    mutex my_mutex;


};

////////////////////////////////////多把锁
class B  
{
public:
    void inMsgRecvQueue() // 收到的消息入到队列的栈中
    {
        for (int i = 0; i < 10000; ++i)
        {
            cout << "hello" << i << endl;
            lock(my_mutex1, my_mutex2);
            msgRecvQueue.push_back(i);  // 假设数字i为收到的命令 入队列 
            my_mutex2.unlock();
            my_mutex1.unlock();
        }
    }
    bool outMsgProc(int& command)
    {
        lock(my_mutex1, my_mutex2);
        lock_guard<mutex> lck1(my_mutex1,adopt_lock);  
        lock_guard<mutex> lck2(my_mutex2,adopt_lock);  
        if (!msgRecvQueue.empty())
            {
                command = msgRecvQueue.front();
                msgRecvQueue.pop_front();
                return true;
            }
        return false;

    }
    void outMsgRecvQueue()
    {
        int command = 0;
     
        for (int i = 0; i < 10000; ++i)
        { 
            bool result = outMsgProc(command);
            if (result == true)   cout << "取出命令: " << command << endl;
            else  cout<< "the outMsgRecvQueue is empty!" <<endl;
        }
        cout << "end!!!!!!!!!!!" <<endl;
    }


private:
    list<int> msgRecvQueue;
    mutex my_mutex1;
    mutex my_mutex2;


};
vector<int> vec= {1,2,3};
void PringDemo(int num)
{
    // cout << num << "线程开始～～～" << endl;
    cout << "ID: " << this_thread::get_id() << vec[0] << vec[1] << vec[2] << endl;
    // cout << num << "线程结束～～～" << endl;
}
int main()
{
    // vector<thread> threads;
    // for(int i = 0; i < 10; ++i)
    // {
    //     threads.push_back(thread(PringDemo, i));
    // }
    // for (auto ite = threads.begin(); ite != threads.end(); ite++)
    // {
    //     ite -> join();
    // }
    // cout << "主进程结束！！！" << endl;

    A a1;
    thread AoutObj(&A::outMsgRecvQueue, &a1);
    thread AinObj(&A::inMsgRecvQueue,&a1);
    AinObj.join();
    AoutObj.join();
     
    /* 锁
    lock() unlock() 必须同时使用 防止忘记unlock() 
    引入std::lock_guard类模版  系统unlock() 不再可以和前两者同时使用
    lock_guard 可以不如 前两者灵活 可以使用{}定义作用域
    */


    B b1; // 多把锁锁住
    thread BoutObj(&B::outMsgRecvQueue, &b1);
    thread BinObj(&B::inMsgRecvQueue,&b1);
    BinObj.join();
    BoutObj.join();
    /*死锁
    多个线程不同顺序互相执行多把锁
    1. 保证多把锁的顺序一样
    2. 使用std::lock()模版函数 用处理多个互斥量    一次可以锁住两个及以上的互斥量 不存在死锁问题
        要么两个互斥量都锁住 要么两个互斥量都没锁住  如果只锁部分锁 另外只要没锁成功 就立即把锁住的锁解锁
        std::lock(mutex1,mutex2,mutex3........)  ====> 然后解锁   
        使用std::lock_guard && std::adopt_lock参数
        adopt_lock是个结构体对象 标记作用: 互斥量已经lock() 不需要在析构函数里再对mutex再加锁
    */



    return 0;

}
