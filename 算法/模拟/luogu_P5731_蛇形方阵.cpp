#include <iostream>
#include <cstring>
using namespace std;
const int N = 15;
int arr[N][N];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main()
{
    memset(arr,0,sizeof(arr));
    int n;
    cin >> n;
    int x = 1;
    int y = 1;
    arr[x][y] = 1;
    int pos = 0;
    for(int i = 2;i <= n * n;i++)
    {
        int tmp_x = x + dx[pos];
        int tmp_y = y + dy[pos];
        if(tmp_x < 1 || tmp_x > n || tmp_y < 1 || tmp_y > n || arr[tmp_x][tmp_y] != 0)
        {
            pos = (pos + 1) % 4;
            tmp_x = x + dx[pos];
            tmp_y = y + dy[pos];
        }
        x = tmp_x;
        y = tmp_y;
        arr[x][y] = i;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            printf("%3d",arr[i][j]);
        }
        cout << endl;
    }
    return 0;
}