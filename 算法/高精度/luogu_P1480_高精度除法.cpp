#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N],c[N],b;
int la,lc;
void div(int c[],int a[],int b)
{
    ll t = 0;
    for(int i = la - 1;i >= 0;i--)
    {
        t = t * 10 + a[i];
        c[i] = t / b;
        t %= b;
    }
    while(lc > 1 && c[lc - 1] == 0)
        lc--;
}
int main()
{
    string x;
    cin >> x >> b;
    la = x.size();
    lc = la;
    for(int i = 0;i < la;i++)
    {
        a[la - 1 - i] = x[i] - '0';
    }
    div(c,a,b);
    for(int i = lc - 1;i >= 0;i--)
    {
        cout << c[i];
    }
    return 0;
}