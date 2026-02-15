#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a = "hello";
    string b("world");
    string c = a + ' ' + b;
    cout << c << endl;
    c += " hai world";
    cout << c << endl;
    return 0;
}