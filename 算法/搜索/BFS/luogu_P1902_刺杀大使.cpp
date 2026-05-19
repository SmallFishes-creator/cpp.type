#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int,int>;
const int N = 1e3 + 10;
int way[N][N];
int arr[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int l = N;
int r = -N;
int n,m;
int ans;
int bfs(int x,int y,int nmax)
{
    memset(way,0,sizeof way);
    way[x][y] = 1;
    queue<PII> q;
    q.push({x,y});
    while(q.size())
    {
        PII t = q.front();
        q.pop();
        int a = t.first;
        int b = t.second;
        for(int i = 0;i < 4;i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !way[nx][ny] && arr[nx][ny] <= nmax)
            {
                way[nx][ny] = 1;
                if(nx == n)
                    return 1;
                else
                    q.push({nx,ny});
            }
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> arr[i][j];
            l = min(l,arr[i][j]);
            r = max(r,arr[i][j]);
        }
    }
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(bfs(1,1,mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}