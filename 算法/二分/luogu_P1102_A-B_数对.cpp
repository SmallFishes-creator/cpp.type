#include <iostream>
#include <algorithm>
const int N = 2e5 + 10;
int arr[N];
using namespace std;
int main()
{
    int n,c;
    cin >> n >> c;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1,arr + n + 1);
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        ans += (upper_bound(arr + 1,arr + 1 + n,arr[i] + c) - lower_bound(arr + 1,arr + 1 + n,arr[i] + c));
    }
    cout << ans;
    return 0;
}