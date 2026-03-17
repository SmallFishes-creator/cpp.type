#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    string s;
    int p1,p2,p3;
    cin >> p1 >> p2 >> p3;
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if(i == 0 || i == s.size() - 1)
            continue;
        if(s[i] == '-' && s[i - 1] >= 'a' && s[i - 1] < s[i + 1] && s[i + 1] <= 'z')
        {
            string tmp;
            if(p3 == 1)
            {
                for(char i = s[i - 1] + 1;i <= s[i + 1] - 1;i++)
                {
                    for(int j = 0;j < p2;j++)
                        tmp.push_back(i);
                }
            }
            else
            {
                for(char i = s[i + 1] - 1;i >= s[i - 1] + 1;i--)
                {
                    for(int j = 0;j < p2;j++)
                        tmp.push_back(i);
                }
            }
            if(p1 == 2)
                transform(tmp.begin(),tmp.end(),tmp.begin(),::toupper);
            if(p2 == 3)
            {
                for(int i = 0;i < tmp.size();i++)
                {
                    tmp[i] = '*';
                }
            }

        }
    }
    return 0;
}