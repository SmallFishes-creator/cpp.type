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
    return 0;
}