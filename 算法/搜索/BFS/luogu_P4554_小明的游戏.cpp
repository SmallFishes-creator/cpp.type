#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
using PII = pair<int,int>;
const int N = 510;
int n,m;
int sx,sy,tx,ty;
int way[N][N];
char arr[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
void bfs()
{
    deque<PII> q;
    q.push_front({sx,sy});
    way[sx][sy] = 0;
    while(q.size())
    {
        PII t = q.front();
        int a = t.first;
        int b = t.second;
        q.pop_front();
        for(int i = 0;i < 4;i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            int flag = 1;
            if(arr[a][b] == arr[nx][ny])
                flag = 0;
            if(way[a][b] + flag >= way[nx][ny])
                continue;
            way[nx][ny] = way[a][b] + flag;
            if(flag)
                q.push_back({nx,ny});
            else
                q.push_front({nx,ny});
        }
    }
}
int main()
{
    cin >> n >> m;
    while(n || m)
    {
        memset(way,0x3f,sizeof way);
        memset(arr,0,sizeof arr);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> arr[i][j];
            }
        }
        cin >> sx >> sy >> tx >> ty;
        sx++,sy++,tx++,ty++;
        bfs();
        cout << way[tx][ty] << endl;
        cin >> n >> m;
    }
    return 0;
}