#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main(void)
{
    int n;
    cin >> n;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i = 0;i < n;i++)
    {
        ll cur;
        cin >> cur;
        q.push(cur);
    }
    ll ans = 0;
    while(q.size() > 1)
    {
        int cur1,cur2;
        cur1 = q.top();
        q.pop();
        cur2 = q.top();
        q.pop();
        ans += (cur1 + cur2);
        q.push(cur1 + cur2);
    }
    cout << ans;
    return 0;
}