#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
int p1,p2,p3;
string s;
void finish(int& i)
{
    string tmp;
    if(p3 == 1)
    {
        for(char k = s[i - 1] + 1;k <= s[i + 1] - 1;k++)
        {
            for(int j = 0;j < p2;j++)
                tmp.push_back(k);
        }
    }
    else
    {
        for(char k = s[i + 1] - 1;k >= s[i - 1] + 1;k--)
        {
            for(int j = 0;j < p2;j++)
                tmp.push_back(k);
        }
    }
    if(p1 == 2)
        transform(tmp.begin(),tmp.end(),tmp.begin(),::toupper);
    if(p1 == 3)
    {
        for(int i = 0;i < tmp.size();i++)
        {
            tmp[i] = '*';
        }
    }
    s.replace(i,1,tmp);
    i += tmp.size() - 1;
}
int main()
{
    cin >> p1 >> p2 >> p3;
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if(i == 0 || i == s.size() - 1)
            continue;
        if(s[i] == '-' && s[i - 1] >= 'a' && s[i - 1] < s[i + 1] && s[i + 1] <= 'z')
        {
            finish(i);
        }
        if(s[i] == '-' && s[i - 1] >= '0' && s[i - 1] < s[i + 1] && s[i + 1] <= '9')
        {
            finish(i);
        }
    }
    for(char e : s)
    {
        cout << e;
    }
    return 0;
}