#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll arr[N];
int n;
ll m;
ll calc(ll x)
{
    ll ret = 0;
    for(ll i = 1;i <= n;i++)
    {
        if(arr[i] - x > 0)
            ret += (arr[i] - x);
    }
    return ret;
}
int main()
{
    ll Max = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
    {
        cin >> arr[i];
        Max = max(Max,arr[i]);
    }
    ll left = 0;
    ll right = Max;
    while(left < right)
    {
        int mid = (left + right + 1) / 2;
        if(calc(mid) >= m) left = mid;
        else right = mid - 1;
    }
    cout << left;
    return 0;
}