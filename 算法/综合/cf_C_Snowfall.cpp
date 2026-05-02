#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
bool cmp(ll e1,ll e2)
{
    if(e1 % 6 == 0 && e2 % 6 != 0) return true;
    if(e1 % 6 != 0 && e2 % 6 == 0) return false;
    if(e1 % 6 == 0 && e2 % 6 == 0) return e1 > e2;
    if(e1 % 3 == 0 && e2 % 3 != 0) return true;
    if(e1 % 3 != 0 && e2 % 3 == 0) return false;
    if(e1 % 3 == 0 && e2 % 3 == 0) return e1 > e2;
    if(e1 % 2 == 0 && e2 % 2 != 0) return false;
    if(e1 % 2 != 0 && e2 % 2 == 0) return true;
    if(e1 % 2 == 0 && e2 % 2 == 0) return e1 > e2;
    return e1 > e2;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> arr;
        for(int i = 0;i < n;i++)
        {
            ll tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }
        if(n == 1)
            cout << arr[0];
        else
        {
        sort(arr.begin(),arr.end(),cmp);
        for(auto e : arr)
            cout << e << ' ';
        }
        cout << endl;
    }
    return 0;
}