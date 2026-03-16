#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = n;i >= 0;i--)
    {
        int num;
        cin >> num;
        //1.符号
        if(num > 0)
        {
            if(i != n)
                cout << '+';
        }
        else if(num < 0)
        {
            cout << '-';
        }
        else
            continue;
        //2.数字
        num = abs(num);
        if(i == 0)
        {
            cout << num;
        }
        else if(num != 1 && i != 0)
            cout << num;
        //3.未知数
        if(i != 0)
        {
            if(i == 1)
                cout << "x";
            else
                cout << "x^" << i;
        }
    }
    return 0;
}