#include <iostream>
using namespace std;
int n,w;
int arr[20];
bool flag[20];
int ans = 1e6;
int ret;
int space[20];//记录已用空间
void dfs(int pos)
{
    if(ret >= ans)
        return;
    if(pos > n)
    {
        ans = min(ret,ans);
        return;
    }
    for(int j = 1;j <= ret;j++)
    {
        if(w - space[j] >= arr[pos])
        {
            space[j] += arr[pos];
            dfs(pos + 1);
            space[j] -=arr[pos];
        }
    }
    ret++;
    space[ret] += arr[pos];
    flag[pos] = true;
    dfs(pos + 1);
    space[ret] -= arr[pos];
    ret--;
}
int main()
{
    cin >> n >> w;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}