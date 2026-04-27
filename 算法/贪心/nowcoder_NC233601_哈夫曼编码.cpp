#include <iostream>
#include <queue>
#include <functional>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i = 0;i < n;i++)
    {
        ll tmp;
        cin >> tmp;
        q.push(tmp);
    }
    ll total = 0;
    while(q.size() > 1)
    {
        ll cur1,cur2;
        cur1 = q.top();
        q.pop();
        cur2 = q.top();
        q.pop();
        ll cur = cur1 + cur2;
        total += cur;
        q.push(cur);
    }
    cout << total;
    return 0;
}