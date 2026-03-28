#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll a[N];
ll f[N];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        f[i] = a[i] - a[i - 1];
    }
    while(m--)
    {
        ll l,r,k;
        cin >> l >> r >> k;
        f[l] += k;
        f[r + 1] -= k;
    }
    for(int i = 1;i <= n;i++)
    {
        f[i] = f[i] + f[i - 1];
        cout << f[i] << ' ';
    }
    return 0;
}