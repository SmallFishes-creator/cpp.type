#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Node{
    int x;
    int y;
}node;
const int N = 1e3 + 10;
int INF = 0x3f3f3f;
int n,m;
char arr[N][N];
int f[4][N][N];
deque<node> record[4];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
void bfs(int num)
{
    while(record[num].size())
    {
        node t = record[num].front();
        record[num].pop_front();
        for(int i = 0;i < 4 ;i++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m || arr[nx][ny] == '#')
                continue;
            int flag = 0;
            if(arr[nx][ny] == '.')
                flag = 1;
            if(f[num][t.x][t.y] + flag < f[num][nx][ny])
            {
                f[num][nx][ny] = f[num][t.x][t.y] + flag;
                if(flag)
                    record[num].push_back({nx,ny});
                else
                    record[num].push_front({nx,ny});
            }
        }
    }
}
int main()
{
    memset(f,0x3f,sizeof f);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == '1')
            {
                record[1].push_front({i,j});
                f[1][i][j] = 0;
            }
            else if(arr[i][j] == '2')
            {
                record[2].push_front({i,j});
                f[2][i][j] = 0;
            }
            else if(arr[i][j] == '3')
            {
                record[3].push_front({i,j});
                f[3][i][j] = 0;
            }
        }
    }
    for(int i= 1;i <= 3;i++)
    {
        bfs(i);
    }
    int ans = INF;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(f[1][i][j] >= INF || f[2][i][j] >= INF ||f[3][i][j] >= INF)
                continue;
            if(arr[i][j] == '.')
                ans = min(ans,f[1][i][j] + f[2][i][j] + f[3][i][j] - 2);
            else if(arr[i][j] != '#')
                ans = min(ans,f[1][i][j] + f[2][i][j] + f[3][i][j]);
        }
    }
    if(ans != INF)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}