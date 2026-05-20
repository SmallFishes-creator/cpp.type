#include <iostream>
#include <queue>
using namespace std;
using PII = pair<int,int>;
const int N = 40;
int arr[N][N];
int record[N][N];
int n;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
void bfs(int x,int y)
{
    queue<PII> q;
    q.push({x,y});
    record[x][y] = 1;
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
            if(nx < 1 || ny < 1 || nx > n || ny > n || record[nx][ny])
                continue;
            record[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cin >> arr[i][j];
            record[i][j] = arr[i][j];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(i == 1 || j == 1 || i == n || j == n)
            {
                if(record[i][j] == 0)
                    bfs(i,j);
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(record[i][j] == 0)
                arr[i][j] = 2;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j= 1;j <= n;j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}