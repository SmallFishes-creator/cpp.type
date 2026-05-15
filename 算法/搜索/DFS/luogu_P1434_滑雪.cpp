#include <iostream>
#include <cstring>
using namespace std;
int arr[110][110];
int way[110][110];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int r,c;
int ans = -1;
int dfs(int x,int y)
{
    if(way[x][y] != -1)
        return way[x][y];
    int ret = 1;
    for(int i = 0;i < 4;i++)
    {
        if(x + dx[i] >= 1 && y + dy[i] >= 1 && x + dx[i] <= r && y + dy[i] <= c && arr[x + dx[i]][y + dy[i]] < arr[x][y])
        {
            ret = max(ret,1 + dfs(x + dx[i],y + dy[i]));
        }
    }
    way[x][y] = ret;
    ans = max(ans,ret);
    return way[x][y];
}
int main()
{
    memset(way,-1,sizeof way);
    cin >> r >> c;
    for(int i = 1;i <= r;i++)
    {
        for(int j = 1;j <= c;j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i = 1;i <=r;i++)
    {
        for(int j = 1;j <= c;j++)
        {
            dfs(i,j);
        }
    }
    cout << ans;
    return 0;
}