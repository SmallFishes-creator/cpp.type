#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll f[N];
int main()
{
    int n,m;
    cin >> n >> m;
    int x;
    cin >> x;
    for(int i = 2;i <= m;i++)
    {
        int y;
        cin >> y;
        if(y > x)
        {
            f[x]++;
            f[y]--;
        }
        else
        {
            f[y]++;
            f[x]--;
        }
        x = y;
    }
    for(int i = 1;i <= n;i++)
    {
        f[i] = f[i] + f[i - 1];
    }
    ll ret = 0;
    for(int i = 1;i < n;i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        ret += min(a * f[i],c + b * f[i]);
    }
    cout << ret;
    return 0;
}