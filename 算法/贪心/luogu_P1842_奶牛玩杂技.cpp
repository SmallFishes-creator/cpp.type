#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
bool cmp(pair<int,int> e1,pair<int,int> e2)
{
    return e1.first + e1.second < e2.first + e2.second;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    for(int i = 0;i < n;i++)
    {
        pair<int,int> cur;
        cin >> cur.first >> cur.second;
        arr.push_back(cur);
    }
    sort(arr.begin(),arr.end(),cmp);
    ll total = -1e10;
    ll up = 0;
    for(int i = 0;i < arr.size();i++)
    {
        ll num = up - arr[i].second;
        total = max(total,num);
        up += arr[i].first;
    }
    cout << total;
    return 0;
}