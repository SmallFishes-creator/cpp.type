#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
using PII = pair<int,int>;
const int N = 1e3 + 10;
int n,m;
int arr[N][N];
int memo[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
void bfs()
{
    queue<PII> q;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(arr[i][j])
            {
                memo[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    while(q.size())
    {
        PII t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for(int i = 0;i < 4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && memo[nx][ny] == -1)
            {
                memo[nx][ny] = memo[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(memo,-1,sizeof memo);
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        for(int j = 1;j <= m;j++)
        {
            arr[i][j] = s[j - 1] - '0';
        }
    }
    bfs();
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cout << memo[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}