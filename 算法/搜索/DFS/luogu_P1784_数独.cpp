#include <iostream>
using namespace std;
int arr[10][10];
bool row[10][10];
bool col[10][10];
bool gong[10][10];
void dfs(int x,int y)
{
    if(arr[x][y] != 0)
    {
        if(x == 9 && y == 9)
        {
            for(int i = 1;i <= 9;i++)
            {
                for(int j = 1;j <= 9;j++)
                {
                    cout << arr[i][j] << ' ';
                }
                cout << endl;
            }
            exit(0);
        }
        else if(y == 9) dfs(x + 1,1);
        else dfs(x,y + 1);
    }
    else
    {
        for(int i = 1;i <= 9;i++)
        {
            if(row[x][i] == false && col[y][i] == false && gong[(x - 1) / 3 * 3 + (y - 1) / 3][i] == false)
            {
                arr[x][y] = i;
                row[x][i] = col[y][i] = gong[(x - 1) / 3 * 3 + (y - 1) / 3][i] = true;
                if(x == 9 && y == 9)
                {
                    for(int i = 1;i <= 9;i++)
                    {
                        for(int j = 1;j <= 9;j++)
                        {
                            cout << arr[i][j] << ' ';
                        }
                        cout << endl;
                    }
                    exit(0);
                }
                else if(y == 9) dfs(x + 1,1);
                else dfs(x,y + 1);
                arr[x][y] = 0;
                row[x][i] = col[y][i] = gong[(x - 1) / 3 * 3 + (y - 1) / 3][i] = false;
            }
        }
    }
}
int main()
{
    for(int i = 1;i <= 9;i++)
    {
        for(int j = 1;j <= 9;j++)
        {
            int tmp;
            cin >> tmp;
            row[i][tmp] = true;
            col[j][tmp] = true;
            gong[(i - 1) / 3 * 3 + (j - 1) / 3][tmp] = true;
            arr[i][j] = tmp;
        }
    }
    dfs(1,1);
    return 0;
}