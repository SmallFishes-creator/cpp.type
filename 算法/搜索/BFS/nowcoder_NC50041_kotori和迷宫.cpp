#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
using PII = pair<int,int>;
string arr[40];
int way[40][40];
int n,m,x,y;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int step = 0;
int ans = 1e3;
void bfs()
{
    memset(way,-1,sizeof way);
    way[x][y] = 0;
    queue<PII> q;
    q.push({x,y});
    while(q.size())
    {
        PII t = q.front();
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != '*' && way[nx][ny] == -1)
            {
                way[nx][ny] = 1 + way[t.first][t.second];
                if(arr[nx][ny] == 'e')
                {
                    ans = min(way[nx][ny],ans);
                    step++;
                }
                else
                {
                    q.push({nx,ny});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    getchar();
    for(int i = 0;i < n;i++)
        getline(cin,arr[i]);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(arr[i][j] == 'k')
            {
                x = i;
                y = j;
            }
        }
    }
    bfs();
    if(!step)
        cout << -1;
    else
        cout << step << ' ' << ans;
    return 0;
}