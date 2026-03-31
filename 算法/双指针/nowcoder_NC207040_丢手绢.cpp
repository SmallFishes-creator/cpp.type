#include <iostream>
#include <climits>
#include<algorithm>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;
    long long total = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
        total += a[i];
    }
    long long half = total / 2;
    long long ans = 0;
    long long sum = 0;
    int right = 1;
    for(int left = 1;left <= n;left++)
    {
        while(right < left + n && sum + a[right] <= half)
        {
            sum += a[right];
            right++;
        }
        ans = max(ans,sum);
        if(right < left + n)
        {
            ans = max(ans,total - (sum + a[right]));
        }
        sum -= a[left];
    }
    cout << ans;
    return 0;
}