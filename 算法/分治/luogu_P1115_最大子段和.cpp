#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int arr[N];
ll ans;
ll bfs(int left,int right)
{
    if(left == right)
        return arr[left];
    int mid = (left + right) / 2;
    ll ret1 = -1e10;
    ll sum1 = 0;
    for(int i = mid;i >= left;i--)
    {
        sum1 += arr[i];
        ret1 = max(sum1,ret1);
    }
    ll ret2 = -1e10;
    ll sum2 = 0;
    for(int i = mid + 1;i <= right;i++)
    {
        sum2 += arr[i];
        ret2 = max(ret2,sum2);
    }
    ll ret = ret1 + ret2;
    return max(max(ret,bfs(left,mid)),bfs(mid + 1,right));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    cout << bfs(1,n);
    return 0;
}