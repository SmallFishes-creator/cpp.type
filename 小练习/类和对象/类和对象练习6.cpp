#include <iostream>
using namespace std;
class person
{
public:
    person()
    {
        cout << "Function with no arguments" << endl;
    }
    person(int a,int h)
    {
        age = a;
        height = new int(h);
        cout << "Function with arguments" << endl;
    }
    person(const person& p)
    {
        age = p.age;
        height = new int(*p.height);
        cout << "copy constructor" << endl;
    }
    ~person()
    {
        if(height != NULL)
        {
            delete height;
            height == NULL;
        }
        cout << "distructor" << endl;
    }
    int age;
    int* height;
};
int main()
{
    person p1(18,170);
    person p2(p1);
    cout << "p1's age:" << p1.age << endl;
    cout << "p1's height:" << *p1.height << endl;
    cout << "p2's age:" << p2.age << endl;
    cout << "p2's height:" << *p2.height << endl;
    return 0;
}