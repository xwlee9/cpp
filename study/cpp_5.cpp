#include <iostream>
using namespace std;

// // c_str()实现

class CMystring
{
private:
  char* m_str;
  size_t m_length;
public:
  CMystring()
  {
    m_str = new char('\0');
    m_length = 0;
  }

  CMystring(size_t length, char ch)
  {
    m_str = new char[length+1];
    for (size_t i = 0; i < length; i++)
    {
      m_str[i] = ch;
    }
    m_str[length] = '\0';
    m_length = length;
  }

  CMystring(const char* str)
  {
    const char* pStr = str;
    int count = 0;
    while ('\0' != *pStr)
    {
      count++;
      pStr++;
      // cout << count;
    }
    m_str = new char [count+1];
    for (int i = 0; i < count + 1; i++)
    {
      m_str[i] = str[i];
    }
    m_str[count] = '\0';
    m_length = count;
  }

  CMystring(const char* str, size_t length)
  {
    m_str = new char[length+1];
    for (size_t i = 0; i < length; i++)
    {
      m_str[i] = str[i];
    }
    m_str[length] = '\0';
    m_length = length;
  }

  CMystring (const char* str, size_t index, size_t length)
  {
    m_str = new char[length+1];
    for (size_t i = index, j = 0; i < length + index; i++, j++)
    {
      m_str[j] = str[i];
    }
    m_str[length] = '\0';
    m_length = length;
  }

  CMystring (const CMystring& str)
  {
    m_str = new char[str.c_size()+1];
    for (size_t i = 0; i < str.c_size(); i++)
    {
      m_str[i] = str.c_str()[i];
    }
  }

public:
  const char* c_str() const
  {
    return m_str;
  }

  const size_t c_size() const
  {
    return m_length;
  }

  void SetLength(size_t length)
  {
    m_length = length;
  }

  char* &GetStr()
  {
    return m_str;
  }
public:
  ~CMystring()
  {
    if (NULL != m_str)
    {
      delete[] m_str;
    }
  }
};
// 输出运算符重载
ostream &operator << (ostream& os, CMystring& str)
{
  os << str.c_str();
  return os;
}


// 输入运算符重载
istream &operator >> (istream& ist, CMystring& str)
{
  char arr[20] = {0};
  ist >> arr;   //输入包含 '\0'
  int i = 0;
  for (i = 0; arr[i] != '\0'; i++);
 //获取输入长度 i
  /*
  for(init-expr ; test-expr ; update-expr)
　　body-statement

  程序首先初始化表达式init-expr的值，然后进入循环，再循环中先对测试值test-expr求值，
  如果为假，则退出循环，否则执行循环体body-statement，并更新表达式update-expr的值。
  */
  delete[] str.c_str();     // 释放c_str
  str.GetStr() = new char[i+1];

  int j = 0;
  for (j = 0; j<i+1; j++)
  {
    str.GetStr()[j] = arr[j];
  }
  str.SetLength(i);
  return ist;
}
int main()
{
  CMystring mstr;
  const char* mstr1 = mstr.c_str();

  CMystring mstr2(5, 'a');
  cout << mstr2.c_str() << '\n';

  CMystring mstr3("abcde");
  cout << mstr3.c_str() << endl;

  CMystring mstr4 ("abcdef", 3);
  cout << mstr4.c_str() << endl;

  CMystring mstr5 ("abcdefg", 3, 3);
  cout << mstr5.c_str() << endl;

  CMystring mstr6(mstr5);
  cout << mstr6.c_str() << endl;


  CMystring mstr7("nice");
  cout << mstr7 << endl;
  cin >> mstr7;
  cout << mstr7 << endl;


  return 0;
}
