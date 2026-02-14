#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string s1;
    cin >> s1;
    cout << "s1 = " << s1 << endl;
    for(string::iterator e = s1.begin();e < s1.end();e++)
    {
        cout << *e << " ";
    }
    cout << endl;
    return 0;
}