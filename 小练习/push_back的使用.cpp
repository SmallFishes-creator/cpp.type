#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string s = "hello ";
    cout << s << endl;
    s.push_back('w');
    s.push_back('o');
    s.push_back('r');
    s.push_back('l');
    s.push_back('d');
    cout << s << endl;
    for(int i = 0;i < 3;i++)
        s.push_back('x');
    for(int i = 0;i < 3;i++)
    {
        cout << s << endl;
        s.pop_back();
    }
    return 0;
}