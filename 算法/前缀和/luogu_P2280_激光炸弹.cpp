#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
const int N = 5e3 + 10;
int arr[N][N];
int sum[N][N];
int main()
{
    memset(arr,0,sizeof(arr));
    memset(sum,0,sizeof(sum));
    int n,m;
    cin >> n >> m;
    int mx = 0;
    int my = 0;
    while(n--)
    {
        int x,y,v;
        cin >> x >> y >> v;
        x++;
        y++;
        if(x > mx)
            mx = x;
        if(y > my)
            my = y;
        arr[x][y] += v;
    }
    if(mx == 0)mx = 1;
    if(my == 0)my = 1;
    for(int i = 1;i <= mx;i++)
    {
        for(int j = 1;j <= my;j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }
    int Max = INT_MIN;
    if(m > mx && m > my)
        Max = sum[mx][my];
    else if(m > mx)
    {
        for(int j = 1; j <= my - m + 1; j++)
        {
            int total = sum[mx][j + m - 1] - sum[0][j + m - 1] - sum[mx][j - 1] + sum[0][j - 1];
            if(total > Max) Max = total;
        }
    }
    else if(m >= my)
    {
        for(int i = 1; i <= mx - m + 1; i++)
        {
            int total = sum[i + m - 1][my] - sum[i - 1][my] - sum[i + m - 1][0] + sum[i - 1][0];
            if(total > Max) Max = total;
        }
    }
    else
    {
        for(int i = 1;i <= mx - m + 1;i++)
        {
            for(int j = 1;j <= my - m + 1;j++)
            {
                int x1 = i;
                int y1 = j;
                int x2 = i + m - 1;
                int y2 = j + m - 1;
                int total = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +sum[x1 - 1][y1 - 1];
                if(total > Max)
                    Max = total;
            }
        }
    }
    cout << Max;
    return 0;
}