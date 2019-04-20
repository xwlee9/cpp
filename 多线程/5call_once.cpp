#include <iostream>
#include <mutex>
#include <thread>
#include <mutex>

using namespace std;

mutex resource_mutex;
once_flag g_flag;

class CAS
{
    static void CreateInstance()
    {
        m_instance = new CAS();
        static DLCAS dl;
    }
private:
    CAS(){}; //私有化构造函数
    static CAS* m_instance;
public:
    static CAS* Getinstance()
    {
        if (m_instance == NULL) 
        // 双重锁定 如果不为NULL 说明instance已经被new过了
        // 如果为NULL，不一定代表没有被new过
        {
            unique_lock<mutex> mutex1(resource_mutex);
            if (m_instance == NULL)
            {
                m_instance = new CAS();
                static DLCAS dl;            
            }
        }
            return m_instance;
    }
        static CAS* Getinstance_CallOnce()
    {
        call_once(g_flag, CreateInstance); 
        //两个线程同时执行到这里 一个线程要等另一个线程执行完毕后CreateInstance();
        cout << "call_once!!!!!!!!!" <<endl;
        return m_instance;
    }
    class DLCAS // 类中套类 用来释放对象
    {
    public:
        ~DLCAS()
        {
            if (CAS::m_instance)
            {
                delete CAS::m_instance;
                CAS::m_instance = NULL;
            }
        }
    };
    void fun()
    {
        cout << "test" << endl;
    }

};

CAS *CAS::m_instance = NULL;

void mythread()
{
    cout << "start!!!!!!!!!!!" << endl;
    CAS* p = CAS::Getinstance();
    cout << "end!!!!!!!!!!!!!" << endl;
}

void mythread_CallOnce()
{
    cout << "start!!!!!!!!!!!" << endl;
    CAS* p = CAS::Getinstance_CallOnce();
    cout << "end!!!!!!!!!!!!!" << endl;
}
int main(void)
{
    // CAS* p = CAS::Getinstance();  //返回该类的对象指针
    // p -> fun();
    // CAS::Getinstance() -> fun();
    /*
    两个线程 两条通路 
    */
    // thread Aobj(mythread);
    // thread Bobj(mythread);
    // Aobj.join();
    // Bobj.join();
    thread Aobj_once(mythread_CallOnce);
    thread Bobj_once(mythread_CallOnce);
    Aobj_once.join();
    Bobj_once.join();
    return 0;
}