#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int arr[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];
    sort(arr + 1,arr + 1 + n);
    ll ret = 0;
    for(int i = 1;i <= n / 2;i++)
    {
        ret += (arr[n + 1 - i] - arr[i]);
    }
    cout << ret;
    return 0;
}