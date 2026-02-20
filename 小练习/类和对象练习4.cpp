#include <iostream>
//函数的分类和调用
//按照有无参分类:有参构造函数 无参构造函数（默认构造函数）
//按照函数类型分类：普通构造函数 拷贝构造函数
using namespace std;
class person
{
public:
    //有参构造函数
    person(int a)
    {
        age = a;
        cout << "Function with arguments!" << endl;
    }
    //无参构造函数
    person()
    {
        cout << "Function with no arguments!" << endl;
    }
    //拷贝构造函数
    person(const person& p)
    {
        age = p.age;
        cout << "copy constructor!" << endl;
    }
    //析构函数
    ~person()
    {
        cout << "Destructor!" << endl;
    }
    int age;
};
//调用
void test01()
{
    //1.括号法
    person p1; //默认构造函数的调用
    person p2(10);//有参构造函数的调用
    person p3(p2);//拷贝构造函数的调用
    cout << "p2's age:" << p2.age << endl;
    cout << "p3's age:" << p3.age << endl;
}
void test02()
{
    //2.显示法
    person p1;//默认构造函数
    person p2 = person(10);//有参构造函数
    person p3 = person(p2);//拷贝构造函数
}
void test03()
{
    person p1 = 10;//有参构造函数
    person p2 = p1;//拷贝构造函数
}
int main()
{
    //1.括号法
    test01();
    cout << "-------------" << endl;
    //2.显示法
    test02();
    cout << "-------------" << endl;
    //3.隐式转换法
    test03();
    return 0;
}