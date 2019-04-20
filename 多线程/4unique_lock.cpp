#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>

using namespace std;

class A
{
public:
    unique_lock<mutex> rtn_uni_lock() // 所有权的转移 return unique_lock<mutex>
    {
        unique_lock<mutex> tmp_uni_lock(my_mutex);
        return tmp_uni_lock;  //从函数返回局部的unique_lock对象是可以的 移动构造函数 
                            //返回局部对象会导致系统生成临时的unique_lock对象 并且调用unique_lock的移动构造函数
    }
    void inMsgRecvQueue() 
    {
        for (int i = 0; i < 10000; ++i)
        {
            unique_lock<mutex> lck(my_mutex, try_to_lock); 

            /*unique_lcok的defer_lock参数           lck.lock(); // 自动解锁

            unique_lock<mutex> lck(my_mutex, refer_lock);
            lck.lock();
            // ........... code ...........
            lck.unlock();
            if(lck.try_lock() == true)
            {
                ........
            }
            else ...............

            */

            /*  unique_lock的release参数

            unique_lock<mutex> lck(my_mutex);
            timed_mutex *px = lck.release();
            // ..........code..........
            px->unlock(); //自己解除

            */

           /*unique_lock 转移所有权 
           std::unique_lock<std::mutex> uni_lock(std::move(uni_lock))
           */


            if (lck.owns_lock())
            {
                cout << "hello" << i << endl;
                msgRecvQueue.push_back(i);
            }
            else cout << "**************未拿到锁************" << endl;
        }
    }
    bool outMsgProc(int& command)
    {
        my_mutex.lock();  //先lock 
        unique_lock<mutex> lck(my_mutex, adopt_lock); 
        chrono::milliseconds sleep_time(200);  // ms
        this_thread::sleep_for(sleep_time); //休息0.2s
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
    mutex my_mutex;
};


int main(void)
{
    A a1;
    thread AoutObj(&A::outMsgRecvQueue, &a1);
    thread AinObj(&A::inMsgRecvQueue,&a1);
    AinObj.join();
    AoutObj.join();

    return 0;

}