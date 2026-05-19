#include <iostream>
#include <queue>
using namespace std;
using PII = pair<int,int>;
const int N = 110;
int n,m;
char arr[N][N];
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
void bfs(int x,int y)
{
    queue<PII> q;
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
            if(nx < 1 || nx > n || ny < 1 || ny > m || arr[nx][ny] == '.')
                continue;
            arr[nx][ny] = '.';
            q.push({nx,ny});
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(arr[i][j] == 'W')
            {
                ans++;
                bfs(i,j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}