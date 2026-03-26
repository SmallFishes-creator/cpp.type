#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll; 
const int N = 1e3 + 10;
int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    ll arr[N][N];
    memset(arr,0,sizeof(arr));
    ll sum[N][N];
    memset(sum,0,sizeof(sum));
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}