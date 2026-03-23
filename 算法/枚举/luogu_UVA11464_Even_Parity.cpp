#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 20;
int arr[N][N];
int main()
{
    int t;
    cin >> t;
    for(int T = 1;T <= t;T++)
    {
        int n;
        cin >> n;
        memset(arr,0,sizeof(arr));
        //输入
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                cin >> arr[i][j];
            }
        }
        int Min = n * n + 1;
        for(int cur = 0;cur <= (1 << n) - 1;cur++)
        {
            int total = 0;
            int tmp[N][N];
            memcpy(tmp,arr,sizeof(arr));
            //第一行
            for(int j = 0;j < n;j++)
            {
                if(((cur >> j) & 1) && tmp[0][j] == 0)
                {
                    tmp[0][j] ^= 1;
                    total++;
                }
            }
            //2~n-1行
            int dx[4] = {1,0,-1,0};
            int dy[4] = {0,1,0,-1};
            //右下左上
            int wfh = 0;
            for(int i = 0;i < n - 1;i++)
            {
                int fz = 0;
                for(int j = 0;j < n;j++)
                {
                    int num = 0;
                    for(int k = 0;k < 4;k++)
                    {
                        int y = i + dy[k];
                        int x = j + dx[k];
                        if(x >= 0 && y >= 0 && x < n && y < n)
                            num += tmp[y][x];
                    }
                    if(num % 2 != 0)
                    {
                        if(tmp[i + 1][j] == 0)
                        {
                            tmp[i + 1][j] ^= 1;
                            total++;
                        }
                        else
                        {
                            fz = 1;
                            break;
                        }
                    }
                }
                if(fz == 1)
                {
                    wfh = 1;
                    break;
                }
            }
            if(wfh == 1)
                continue;
            //检验
            int flag = 1;
            for(int j = 0;j < n;j++)
            {
                int num = 0;
                for(int k = 0;k < 4;k++)
                {
                    int y = n - 1 + dy[k];
                    int x = j + dx[k];
                    if(x >= 0 && y >= 0 && x < n && y < n)
                        num += tmp[y][x];
                }
                if(num % 2 != 0)
                {
                    flag = 0;
                    break;
                }

            }
            if(total < Min && flag)
                Min = total;
        }
        cout << "Case " << T << ": ";
        if(Min == n * n + 1)
            cout << -1 << endl;
        else
            cout << Min << endl;
    }
    return 0;
}