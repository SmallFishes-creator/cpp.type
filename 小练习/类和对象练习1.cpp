#include <iostream>
#include <string>
using namespace std;
class student
{
public:
    string name;
    string stu_num;
    void print()
    {
        cout << "student's name:" << name << endl;
        cout << "student number:" << stu_num << endl;
    }
};
int main()
{
    student s1;
    s1.name = "zhangsan";
    s1.stu_num = "2505110209";
    s1.print();
    return 0;
}