#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;
const int N = 20;
int arr[N][N];
int row[N];
int col[N];
int tmp[N][N];
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
    {
        int sum = 0;
        for(int j = 1;j <= m;j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        row[i] = sum;
    }
    int ans = 0;
    for(int i = 0;i <= ((1 << n) - 1);i++)
    {
        memcpy(tmp,arr,sizeof(arr));
        int cur1 = 0;
        int ret = 0;
        for(int j = 1;j <= n;j++)
        {
            if((i >> (j - 1)) & 1)
            {
                ret += row[j];
                for(int t = 1;t <= m;t++)
                {
                    tmp[j][t] = 0;
                }
                cur1++;
            }
        }
        if(cur1 > k)
            continue;
        int cur2 = k - cur1;
        for(int j = 1;j <= m;j++)
        {
            int sum = 0;
            for(int t = 1;t <= n;t++)
            {
                sum += tmp[t][j];
            }
            col[j] = sum;
        }
        sort(col + 1,col + 1 + m,greater<int>());
        for(int j = 1;j <= cur2 && j <= m;j++)
        {
            ret += col[j];
        }
        ans = max(ans,ret);
    }
    cout << ans << endl;
    return 0;
}