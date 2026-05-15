#include <iostream>
using namespace std;
short arr[10010][10010];
int t,p;
int dfs(int x,int y)
{
    if(arr[x][y] == -1)
        return -1;
    if(arr[x][y])
        return arr[x][y];
    arr[x][y] = -1;
    if(!x)
    {
        arr[x][y] = 1;
        return 1;
    }
    if(!y)
    {
        arr[x][y] = 2;
        return 2;
    }
    int num = (x + y) % p;
    arr[x][y] = dfs(num,(num % p + y) % p);
    return arr[x][y];
}
int main()
{
    cin >> t >> p;
    int x,y;
    while(t--)
    {
        cin >> x >> y;
        int tmp = dfs(x,y);
        if(tmp == -1)
            cout << "error" << endl;
        else if(tmp == 1)
            cout << '1' << endl;
        else
            cout << '2' << endl;
    }
    return 0;
}