#include <iostream>
// 包含 vector list deque map multimap
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>

using namespace std;

// string 容量 capacity 少于15个 申请15个容量 多余就申请16个字节   vc6.0为31
// reserve 修改容量 只能增加 按照每16个字节增加
void STLDef()
{
  vector<int> vec;
}

void fun_fe(int i)
{
  cout << i ;
}

void STLStru()
{
  vector<int> v1;

  vector<int> v2(5);
  for(int i = 0; i < 5; i++)
  {
    cout << v2[i];          //00000
  }
  cout << endl;

  vector<int> v3(5, 1);   //(num, int)
  for(int i = 0; i < 5; i++)
  {
    cout << v3[i];          //11111
  }
  cout << endl;

  vector<int> v4(v3);   //v3初始化v4
  for(int i = 0; i < 5; i++)
  {
    cout << v4[i];          //11111
  }
  cout << endl;

  vector<int>::iterator ite = v4.begin();
  vector<int>::iterator ite1 = v4.end();

  vector<int> v5(ite, ite1);
  for(int i = 0; i < 5; i++)
  {
    cout << v5[i];          //11111
  }
  cout << endl;
// //  容量  基于macos测试
  cout << v5.capacity() << endl;      // 5
  v5.push_back(1);  // 增加空间
  cout << v5.capacity() << endl;      //10
  v5.push_back(1);
  v5.push_back(1);
  v5.push_back(1);
  v5.push_back(1);
  v5.push_back(1);
  v5.push_back(1);
  v5.push_back(1);
  cout << v5.capacity() << endl;      //20
  v5.reserve(22);
  cout << v5.capacity() << endl;       //22

  cout << v5.size() <<endl;            //13
// // resize 大于空间容量就会重新申请空间
  v5.resize(10);
  cout << v5.size() << endl;           //10
  cout << v1.empty() << endl;          //1

// =====================增删改查
  for(int i = 0; i < 10; i++)
  {
    v1.push_back(i);
  }

  for(int i = 0; i < 10; i++)
  {
    cout << v1[i];                        //0123456789
  }
  cout << endl;
// ============输出单个元素 at() [] begin() back()
  for(int i = 0; i < 10; i++)             // at在越界的时候会抛出异常 更安全
  {
    cout << v1.at(i);                       //0123456789
  }
  cout << endl;
  cout << v1.back() << endl;                       //9
  // cout << v1.begin() << endl;                      //0

// ============输出全部
  vector<int>::iterator ite2;
  ite2 = v1.begin();
  for(ite2; ite2 != v1.end(); ite2++)
  {
    cout << *ite2 << " ";                       //0 1 2 3 4 5 6 7 8 9
  }
  cout << endl;

  for_each(v1.begin(),v1.end(),fun_fe);         //0123456789
  cout << endl;
// ============插入    尾添加 push_back
// // v3    //11111
  v3.insert(v3.begin()+1,3);                    //131111  (loc,int)
  for_each(v3.begin(),v3.end(),fun_fe);
  cout << endl;

  v3.insert(v3.begin()+2, 2, 8);
  for_each(v3.begin(),v3.end(),fun_fe);         //13881111 (loc, num, int)
  cout << endl;

  v3.insert(v3.begin()+1, v1.begin()+5, v1.begin()+7);   //add loc5 loc6
  for_each(v3.begin(),v3.end(),fun_fe);         //1563881111  (loc, vector.begin(), vector.end())
  cout << endl;

// ============删除
// 尾删除 pop_back
  v3.pop_back();
  for_each(v3.begin(),v3.end(),fun_fe);         //156388111
  cout << endl;
//删除
  v3.erase(v3.begin()+1);
  for_each(v3.begin(),v3.end(),fun_fe);         //16388111
  cout << endl;

  v3.erase(v3.begin()+5,v3.end());
  for_each(v3.begin(),v3.end(),fun_fe);         //16388
  cout << endl;
//清除所有
// vector.clear()

// ============修改  利用查的方式赋值修改
//赋值 重新赋值清除以前的 assign
//assign(vector.start, vector.stop)
//assign(num, int )
// ============交换
  v3.swap(v1);
  for_each(v3.begin(),v3.end(),fun_fe);         //0123456789
  cout << endl;
  for_each(v1.begin(),v1.end(),fun_fe);         //16388
  cout << endl;

// ============比较
  cout << (v3 > v1) <<endl;                       //0
// ============sort排序
  sort(v1.begin(), v1.end());
  for_each(v1.begin(),v1.end(),fun_fe);         //13688
  cout << endl;

  sort(v3.begin(), v3.end(), greater<int>());
  for_each(v3.begin(),v3.end(),fun_fe);         //9876543210
  cout << endl;
// ============乱序排序
  srand((unsigned int)(time(NULL)));
  random_shuffle(v1.begin(),v1.end());
  for_each(v1.begin(),v1.end(),fun_fe);         //88163
  cout << endl;
}
// //=====================================================list
struct Node
{
  int a;
  char b;
};

struct Node1
{
  int a;
  char b;
  Node1(int d, char f)
  {
    a = d;
    b = f;
  }
  bool operator==(const Node1& g) // remove
  {
    if(g.a == this -> a && g.b == this ->b)
    {
      return true;
    }

    return false;

  }
  bool operator < (const Node1& g) // sort
  {
    if(g.a < this -> a)
    {
      return true;
    }

    return false;

  }
};

void fun_ls(Node& d)
{
  cout << d.a << "  " << (int)d.b <<endl ;
}

void fun_ls1(Node& d)
{
  cout << d.a << "  " << d.b <<endl ;
}

void fun_ls2(Node1& d)
{
  cout << d.a << "  " << d.b <<endl ;
}

void ListDef()
{
  list<Node> ls(5);
  for_each(ls.begin(),ls.end(),fun_ls);

  Node no = {12, 'a'};
  list<Node> ls1(5, no);
  for_each(ls1.begin(),ls1.end(),fun_ls1);

  list<Node> ls2(ls1);
  for_each(ls2.begin(),ls2.end(),fun_ls1);

  list<Node> ls3(ls1.begin(), ls1.end());
  for_each(ls3.begin(),ls3.end(),fun_ls1);

  list<Node>::iterator ite;
  ite = ls1.begin();
  ite++;    // 只支持++ 不支持 ite+2  不是连续的空间


}

void ListSize()
{
  Node no = {22,'x'};
  list<Node> ls(6, no);
  cout << ls.size() <<endl;                       //6
  cout << ls.empty() <<endl;                      //0
  for_each(ls.begin(),ls.end(),fun_ls1);          //6个 22 ‘x’
  ls.resize(3);     // 变成3个
  cout << ls.size() <<endl;                       //3
  for_each(ls.begin(),ls.end(),fun_ls1);          //3个 22 ‘x’
  ls.resize(0);
  cout << ls.empty();                             //1
}

void ListStru()
{
  Node no = {22,'x'};
  list<Node> ls(6, no);
  for (list<Node> ::iterator ite = ls.begin(); ite != ls.end(); ite++)
  {
    cout << ite -> a << "   " << ite -> b << endl;
  }
  // for_each(ls.begin(),ls.end(),fun_ls1);          //6个 22 ‘x’

  cout << ls.back().a << "   " << ls.back().b <<endl;
  cout << ls.front().a << "   " << ls.front().b <<endl;
}

void ListAdd()
{
  list<Node1> ls;
  // Node_1 no(33,'y');
  ls.push_front(Node1(11,'a'));
  ls.push_front(Node1(22,'b'));
  ls.push_back(Node1(33,'c'));
  // for_each(ls.begin(),ls.end(),fun_ls2);          //22  b      11  a     33  c

  list<Node1>::iterator ite = ls.begin();
  ite ++;
  ls.insert(ite,Node1(44,'d'));
  // for_each(ls.begin(),ls.end(),fun_ls2);          //22  b      44  d     11  a     33  c
  ls.insert(ite, 3, Node1(55,'e'));
  list<Node1> ls1(ls);
  // for_each(ls.begin(),ls.end(),fun_ls2);          //22b   44d  55e  55e  55e   11a    33c
// //头尾删除
  ls.pop_back();                                  //22b   44d  55e  55e  55e   11a
  ls.pop_front();                                 //44d  55e  55e  55e   11a
  ls.push_front(Node1(22,'b'));                   //22b   44d  55e  55e  55e   11a
  ls.push_back(Node1(33,'c'));                    //22b   44d  55e  55e  55e   11a    33c
  list<Node1>::iterator ite1 = ls.begin();
  ite1++;
  ite1++;
  ls.erase(ite1);                                 //22b   44d  (ite1) 55e  55e   11a    33c
  ite1++;
  ite1++;
  ls.erase(ite1, --ls.end());                            //22b   44d  55e  (ite1)  33c
  // for_each(ls.begin(),ls.end(),fun_ls2);
  // ls.clear()    //全部清除
  // ls.remove(Node1(22,'b')); //需要在Node1 结构体中将 运算符== 判断重载   Xcode有问题？？？
  // for_each(ls.begin(),ls.end(),fun_ls2);
  // //ls1    //22b   44d  55e  55e  55e   11a    33c
  // ls1.unique();    //      //Xcode有问题？？？
  // for_each(ls1.begin(),ls1.end(),fun_ls2);
// //改
  ls1.assign(3,Node1(66,'c'));                          //66 c  66 c  66 c
  ls1 = ls;                                            //22b   44d  55e     33c
  // for_each(ls1.begin(),ls1.end(),fun_ls2);
// //交换数据
  list<Node1> ls2;
  ls2.push_back(Node1(77,'f'));
  ls2.swap(ls1);
  // for_each(ls1.begin(),ls1.end(),fun_ls2);             //77 f
  // for_each(ls2.begin(),ls2.end(),fun_ls2);              //22b   44d  55e     33c
// //倒转元素
  ls2.reverse();
  // for_each(ls2.begin(),ls2.end(),fun_ls2);                // 33c 55e 44d 22b
// // 排序  sort需要运算符重载
  // ls2.sort();
  // for_each(ls2.begin(),ls2.end(),fun_ls2);       //？？？ 有问题
// // list 合并  两个列被要有顺序 先排序
  ls1.push_back(Node1(33,'c'));
  // ls1.merge(ls2)                                 // ？？？有问题
// // list 拼接
  ls1.splice(ls1.begin(), ls2);
//   for_each(ls1.begin(),ls1.end(),fun_ls2);          //// 33c 55e 44d 22b 77f 33c
// // void splice ( iterator position, list<T,Allocator>& x );  // 
// // void splice ( iterator position, list<T,Allocator>& x, iterator i );
// // void splice ( iterator position, list<T,Allocator>& x, iterator first, iterator last );
// //查找 没有找到 无返回
  list<Node1>::iterator ite3 = find(ls1.begin(), ls1.end(), Node1(22,'f'));
  cout << ite3->a << " " << ite3->b <<endl;

}

void fun_mp(pair<int, char> pr)
{
  cout << pr.first << " " << pr.second << endl;
}




void MapDef()
{
  // typedef pair<int, char> in_pair;    // 可以重命名
  pair<map<int,char>::iterator, bool> ite_b;  //迭代器只能++ 不能+n
  map<int, char> mp; // 键值 实值
  mp.insert(pair<int, char>(11, 'a'));    // pair类型
  ite_b = mp.insert(pair<int, char>(22, 'b'));  //插入成功 second 返回true 否则返回false
  // cout << ite_b.second <<endl;
  mp.insert(pair<int, char>(33, 'c'));
  mp.insert(pair<int, char>(44, 'd'));
  mp.insert(pair<int, char>(55, 'e'));
  mp.insert(pair<int, char>(66, 'f'));
  map<int,char>::iterator ite = mp.begin();
  ite ++;
  ite ++;
  ite ++;
  mp.insert(ite,pair<int, char>(10,'x'));     //
  // for_each(mp.begin(),mp.end(),fun_mp);
  map<int, char> mp1;
  mp.insert(pair<int, char>(77, 'g'));
  mp1.insert(mp.begin(),mp.end());
  // for_each(mp1.begin(),mp1.end(),fun_mp);
  map<int, char> mp2(mp1);
  map<int, char> mp3(mp2.begin(),mp2.end());

  map<int,char>::iterator ite3 = mp3.begin();
  mp3.erase(ite3);    // ite3 mp3.end()
  ite3 = mp3.begin();
  // for (ite3; ite3 != mp3.end(); ite3++)
  // {
  //   cout << ite3 -> first << "  " << ite3 -> second << endl;
  // }
  mp3.erase(11);
  for_each(mp3.begin(),mp3.end(),fun_mp);
  // // 查找 如果有返回节点迭代器
  ite3 = mp.find(22);
  cout << ite3 -> first << " **** " << ite3 -> second <<endl;
  // 若find() 没有  无法输出  指向最后一个元素的下一个 end()
  if (mp3.end() == mp3.find(1))
  {
    cout << "NICE" <<endl;
  }
  // 可以使用 [] 算符访问修改值
  cout << mp2[22] <<endl;
  mp2[22] = 'y';
  cout << mp2[22] <<endl;
  // // 交换 swap
  // // 从大到小
  map<int, char, greater<int> > mp4;
  map<int, char, greater<int> >::iterator ite4;
}

void MapStru()
{
  map<int, char> mp;
  mp.insert(pair<int, char>(11, 'a'));    // pair类型
  mp.insert(pair<int, char>(22, 'b'));
  mp.insert(pair<int, char>(33, 'c'));
  mp.insert(pair<int, char>(44, 'd'));
  mp.insert(pair<int, char>(55, 'e'));

  cout << mp.size() <<endl;
  cout << mp.count(11) <<endl;   // 其实是检测key值是不是存在  返回bool值
  cout << mp.empty() <<endl;    // bool
  map<int, char>::iterator ite = mp.begin();
  for (ite; ite != mp.end(); ite++)
  {
    cout << ite -> first << "  " << ite -> second << endl;
  }
  ite = mp.begin();
  // // lower_bound(key) 返回参数key位置 该位置键不小于key key<=pos
  // // upper_bound(key) 返回参数key位置 该位置键大于key key>pos
  // // mp.equal_range(key) 返回两个迭代器 第一个为lower_bound(key), 第二个是upper_bound(key)
  cout << mp.lower_bound(33) -> first <<endl;      // 33
  cout << mp.lower_bound(34) -> first <<endl;      //44
  cout << mp.upper_bound(33) -> first <<endl;      // 44
  cout << mp.equal_range(33).first -> first  <<endl;
  cout << mp.equal_range(33).second -> first  <<endl;

}


int main()
{
// //========================================================= vector向量
// // 动态空间 空间不够用会重新申请更大的空间 迭代器失效
  // struct Stu
  // {
  //   int age;
  // };
  // vector<struct Stu> vec1;
  // vector<int*> vec2;
  // vector<string> vec3;

  // STLStru();
//  //===================向量容量的问题
// // 初始化几个 容量就是几个 vs中(空间不够时 增加现有空间的一半 ) push_back增加元素
// // reserve() 修改空间 只能变大 设置多大就多大
// // 重新申请空间 迭代器会失效
// // size 获取元素的个数      resize 重新设置元素的个数 容量大小不变
// // empty() 判断对象有没有元素 如果是空 返回1
// //=============== array数组
// // 固定数组
// //=============== valaary 在cmath.h

// //========================================================= list列表
// // list 双向 forward_list 单向
// // vector 访问快 尾添加 不申请空间是快 不支持快速加入删除  list 随机访问慢 支持下标 支持快速插入删除
// // list没有容量的概念 当有新的元素申请空间   不支持下标运算
  // ListDef();
  // ListSize();
  // ListStru();
// ListAdd();
// //========================================================= deque 段连续空间
// // vector 不够就重新分配空间 原来内容复制过去 随机位置插入/删除效率低 随机访问效率高 有下标运算 不支持头添加
// // list 空间不连续  随机位置插入/删除效率  没有随机访问 支持头添加
// // deque 空间不够 申请另外的定量空间 连接在元空间尾巴上 随机位置插入/删除效率低 随机访问效率不高 支持头添加 尾添加
// // 对比vector 没有capacity reserve 多了push_frond,pop_front
  deque<int> dq;
  dq.push_front(11);
  deque <int>::iterator ite = dq.begin();
  // for (ite; ite!= dq.end(); ite++)
  // {
  //    cout << *ite <<endl;
  // }

// //=========================================================关联容器  键值对
// //有序容器      map 键值对 不可以重复   multimap 键值对可以重复     set 键值 实值相同   nultiset 语序重复
// //红黑树  平衡排序二叉树   x = log 2^N   数据大查找效率高  插入效率低于链表  涉及排序


// MapDef();
// MapStru();

// multimap 操作和map一样 键值可以重复 计数count()  find()返回第一个匹配的值

  multimap <int, char> mmp;
  mmp.insert(pair<int, char>(11,'a'));
  mmp.insert(pair<int, char>(11,'a'));
  mmp.insert(pair<int, char>(11,'b'));
  mmp.insert(pair<int, char>(22,'b'));
  mmp.insert(pair<int, char>(33,'c'));
// //unorder_map 无序容器 在boost库中的容器
  multimap <int, char>::iterator ite_mmp = mmp.begin();
  for (ite_mmp; ite_mmp != mmp.end(); ite_mmp++)
  {
    cout << ite_mmp -> first << " *** " << ite_mmp -> second <<endl;
  }
  mmp.find(11);
  return 0;

}
