#include <iostream>
using namespace std;
class person
{
public:
    person()
    {
        cout << "Function with no argument" << endl;
    }
    person(int a)
    {
        age = a;
        cout << "Function with argument" << endl;
    }
    person(const person& p)
    {
        cout << "copy contructor" << endl;
    }
    ~person()
    {
        cout << "distructor" << endl;
    }
    int age;
};
//1.使用一个创建完毕的对象来初始化一个新对象
void test01()
{
    person p1;
    person p2(p1);
}
//2.用值传递的方式给函数参数传值
void work(person p)
{

}
void test02()
{
    person p1;
    work(p1);
}
//3.值的方式返回局部对象
person dowork()
{
    person p1;
    return p1;
}
void test03()
{
    person p2 = dowork();
}
int main()
{
    test01();
    cout << "---------------" << endl;
    test02();
    cout << "---------------" << endl;
    test03();
    return 0;
}