#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
pair<int,ll> arr[N];
bool cmp(const pair<int,ll>& e1,const pair<int,ll>& e2)
{
    return e1.second < e2.second;
}
int FIND(int l,int r,const ll targe)
{
    while(l < r)
    {
        int m = (l + r + 1) / 2;
        if(arr[m].second == targe)
            return m;
        else if(arr[m].second > targe)
            r = m - 1;
        else
            l = m;
    }
    return l;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i].second;
        arr[i].first = i;
    }
    sort(arr + 1,arr + 1 + n,cmp);
    int left = 1;
    int right = n;
    while(left < right)
    {
        ll mid = (arr[left].second + arr[right].second) / 2;
        int m = FIND(left,right,mid);
        if(m - left + 1 >= right - m)
            right--;
        else
            left++;
    }
    cout << arr[left].first;
    return 0;
}