#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
typedef struct Record{
    int T;
    int D;
}record;
vector<record> arr;
int cur[N];
bool cmp(record e1,record e2)
{
    return e1.T * e2.D < e1.D * e2.T;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        int d;
        cin >> t >> d;
        arr.push_back({t,d});
    }
    sort(arr.begin(),arr.end(),cmp);
    ll time = 0;
    ll ans = 0;
    for(int i = 1;i < arr.size();i++)
    {
        time += arr[i - 1].T * 2;
        ans += time * arr[i].D;
    }
    cout << ans;
    return 0;
}