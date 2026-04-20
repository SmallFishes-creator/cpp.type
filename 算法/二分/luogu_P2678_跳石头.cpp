#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e4 + 10;
int arr[N];
int l,n,m;
int calc(int x)
{
    int count = 0;
    int record = 0;
    for(int i = 1;i <= n + 1;i++)
    {
        if(arr[i] - record < x)
            count++;
        else
            record = arr[i];
    }
    return count;
}
int main()
{
    cin >> l >> n >> m;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    arr[n + 1] = l;
    int left = 0;
    int right = l;
    int ans = 0;
    while(left < right)
    {
        int mid = (left + right + 1) / 2;
        if(calc(mid) <= m)
        {
            ans = mid;
            left = mid;
        }
        else right = mid - 1;
    }
    cout << ans;
    return 0;
}