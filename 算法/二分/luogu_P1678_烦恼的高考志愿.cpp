#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int arr1[N];
int arr2[N];
int main()
{
    int m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++)
    {
        cin >> arr1[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> arr2[i];
    }
    long long ans = 0;
    sort(arr1 + 1,arr1 + 1 + m);
    for(int i = 1;i <= n;i++)
    {
        int tmp = lower_bound(arr1 + 1,arr1 + 1 + m,arr2[i]) - arr1;
        if(tmp == 1)
            ans += abs(arr1[tmp] - arr2[i]);
        else if(tmp == 1 + m)
            ans += abs(arr1[tmp - 1] - arr2[i]);
        else
            ans += min(abs(arr1[tmp] - arr2[i]),abs(arr1[tmp - 1] - arr2[i]));
    }
    cout << ans;
    return 0;
}