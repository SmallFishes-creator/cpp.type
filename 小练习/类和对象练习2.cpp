#include <iostream>
#include <string>
using namespace std;
class person
{
private:
    //只写
    string name;
    //只读
    int age = 18;
    //可读可写
    string hobby;
public:
    void set_name(string n)
    {
        name = n;
    }
    int get_age()
    {
        return age;
    }
    void set_hobby(string h)
    {
        hobby = h;
    }
    string get_hobby()
    {
        return hobby;
    }

};
int main(void)
{
    person p1;
    p1.set_name("zhangsan");
    p1.set_hobby("go swimming");
    cout << "his age:" << p1.get_age() << endl;
    cout << "his hobby:" << p1.get_hobby() << endl;
    return 0;
}