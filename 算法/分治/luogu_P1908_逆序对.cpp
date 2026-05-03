#include <iostream>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int arr[N];
int tmp[N];
ll dfs(int left,int right)
{
    if(left >= right)
        return 0;
    ll ret = 0;
    int mid = (left + right) / 2;
    ret += dfs(left,mid);
    ret += dfs(mid + 1,right);
    int cur1 = left;
    int cur2 = mid + 1;
    int i = left;
    while(cur1 <= mid && cur2 <= right)
    {
        if(arr[cur1] <= arr[cur2])
            tmp[i++] = arr[cur1++];
        else
        {
            ret += (mid - cur1 + 1);
            tmp[i++] = arr[cur2++];
        }
    }
    while(cur1 <= mid)
        tmp[i++] = arr[cur1++];
    while(cur2 <= right)
        tmp[i++] = arr[cur2++];
    for(int j = left;j <= right;j++)
    {
        arr[j] = tmp[j];
    }
    return ret;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];
    int left = 1;
    int right = n;
    cout << dfs(left,right) << endl;
    return 0;
}