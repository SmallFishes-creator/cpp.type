#include <iostream>
using namespace std;
using ll = long long;
ll qpow(ll a,ll b,ll p)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ll a,b,p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld",a,b,p,qpow(a,b,p));
    return 0;
}