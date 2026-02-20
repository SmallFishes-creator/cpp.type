#include <iostream>
using namespace std;
class person
{
public:
    person(int a,int b,int c):p_A(a),p_B(b),p_C(c)
    {
        cout << "person's constructor" << endl;
    }
    ~person()
    {
        cout << "person's distructor" << endl;
    }
    int p_A;
    int p_B;
    int p_C;
};
int main()
{
    person p(10,20,30);
    cout << "p_A:" << p.p_A << endl;
    cout << "p_B:" << p.p_B << endl;
    cout << "p_C:" << p.p_C << endl;
    return 0;
}