#include <iostream>
#include <string>
using namespace std;
class phone
{
public:
    phone(string p)
    {
        phone_type = p;
        cout << "phone's contructor" << endl;
    }
    ~phone()
    {
        cout << "phone's distructor" << endl;
    }
    string phone_type;
};
class person
{
public:
    person(string per_n,string ph_t):person_name(per_n),phone1(ph_t)
    {
        cout << "person's contructor" << endl;
    }
    ~person()
    {
        cout << "person's distructor" << endl;
    }
    phone phone1;
    string person_name;
};
int main()
{
    person person1("zhangsan","apple_MAX");
    cout << "--------------" << endl;
    cout << person1.person_name << " have a " << person1.phone1.phone_type << endl;
    cout << "--------------" << endl;
    return 0;
}