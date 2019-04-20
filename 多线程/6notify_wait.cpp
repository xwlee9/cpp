#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>

using namespace std;

class A
{
public:
    void inMsgRecvQueue() 
    {
        for (int i = 0; i < 100000; ++i)
        {
            cout << "hello" << i << endl;
            unique_lock<mutex> lck(my_mutex);  
            msgRecvQueue.push_back(i);
            my_cond.notify_one(); 
            // 我们尝试把wait()的线程唤醒 执行完这行 那么outMsgRecvQueue()里的wait唤醒
            // 若唤醒失败 notify_one() 没有效果 
            // notify_one()只能唤醒一个线程的wait        notify_all()唤醒全部的
            // else cout << "**************未拿到锁************" << endl;
        }
    }

    void outMsgRecvQueue()
    {
        int command = 0;
        while(true)
        {
            unique_lock<mutex> lck1(my_mutex);
            my_cond.wait(lck1, [this]
                {
                if (!msgRecvQueue.empty()) return true;
                return false;    
                });
            command = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            lck1.unlock();
            cout << "执行输出操作，取出：" << command << endl; 
        }
    }

/*
wait() 用来等待一个东西
如果第二个参数 lambda表达式返回true, wait() 直接返回
如果第二个参数 lambda表达式返回fasle，
    那么wait()将解锁互斥量 并堵塞到本行 等到其他线程调用notify_one()成员函数为止
如果没有第二个参数 第二个参数lambda表达式返回false一样
当其他线程用notify_one()将本wait(原本是堵塞\沉睡状态)唤醒 
===> wait()不断尝试重新获取互斥量锁 如果获取不到 流程卡在wait等待这里获取 
    如果获取到锁 wait()继续执行
===> 如果wait有第二个参数(lambda),判断lambda表达式为false ,对互斥量继续解锁
            如果表达式为true, wait返回，流程走下来 此时互斥锁为锁定状态
    如果wait 无第二个参数 
 */           

private:
    list<int> msgRecvQueue;
    mutex my_mutex; 
    condition_variable my_cond; // 生成一个条件变量对象
};


int main(void)
{
    A a1;
    thread AoutObj(&A::outMsgRecvQueue, &a1);
    thread AinObj(&A::inMsgRecvQueue,  &a1);
    AinObj.join();
    AoutObj.join();

    return 0;

}