#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N] = {0};
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        ll x;
        cin >> x;
        a[i] = a[i - 1] + x; 
    }
    ll prevmin = 0;
    ll ret = -1e20;
    for(int i = 1;i <= n;i++)
    {
        ret = max(ret,a[i] - prevmin);
        prevmin = min(prevmin,a[i]);
    }
    cout << ret << endl;
}