#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll arr[N];
ll m = 0,n,k;
ll calc(ll x)
{
    ll ret = 0;
    for(ll i = 1;i <= n;i++)
    {
        ret += arr[i] / x;
    }
    return ret;
}
int main()
{
    cin >> n >> k;
    for(ll i = 1;i <= n;i++)
    {
        cin >> arr[i];
        m = max(arr[i],m);
    }
    ll left = 0,right = m;
    while(left < right)
    {
        int mid = (left + right + 1) / 2;
        if(calc(mid) >= k) left = mid;
        else right = mid - 1;
    }
    cout << left << endl;
    return 0;
}