#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int x,y;
int ans = 0;
int way1(int num)
{
    return num * 2;
}
int way2(int num)
{
    return num + 1;
}
int way3(int num)
{
    return num - 1;
}
int (*way[3])(int) = {way1,way2,way3};
void bfs()
{
    queue<int> q;
    q.push(x);
    arr[x] = 0;
    while(q.size())
    {
        int t = q.front();
        q.pop();
        for(int i = 0;i < 3;i++)
        {
            int pos = way[i](t);
            if(pos > 0 && pos <= 1e5 && arr[pos] == -1)
            {
                arr[pos] = 1 + arr[t];
                if(pos == y)
                {
                    ans = arr[pos];
                    return;
                }
                q.push(pos);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> x >> y;
        memset(arr,-1,sizeof arr);
        bfs();
        cout << ans << endl;
    }
    return 0;
}