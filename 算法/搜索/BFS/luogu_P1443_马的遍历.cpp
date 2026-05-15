#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using PII = pair<int,int>;
int n,m,x,y;
int dx[] = {2,1,-1,-2,-2,-1,1,2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
int arr[410][410];
queue<PII> q;
void bfs()
{
    q.push({x,y});
    while(q.size())
    {
        PII t = q.front();
        q.pop();
        int a = t.first;
        int b = t.second;
        for(int i = 0;i < 8;i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && arr[nx][ny] == -1)
            {
                q.push({nx,ny});
                arr[nx][ny] = arr[a][b] + 1;
            }
        }
    }
}
int main()
{
    memset(arr,-1,sizeof arr);
    cin >> n >> m >> x >> y;
    arr[x][y] = 0;
    bfs();
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}