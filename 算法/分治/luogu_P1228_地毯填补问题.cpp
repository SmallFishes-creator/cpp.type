#include <iostream>
using namespace std;
inline void bfs(int x,int y,int a,int b,int l)
{
    if(l == 1)
        return;
    if(x <= a + l / 2 - 1 && y <= b + l / 2 - 1)
    {
        cout << a + l / 2 << ' ' << b + l / 2 << ' ' << 1 << endl;
        bfs(x,y,a,b,l / 2);
        bfs(a + l / 2,b + l / 2 - 1,a + l / 2,b,l / 2);
        bfs(a + l / 2 - 1,b + l / 2,a,b + l / 2,l / 2);
        bfs(a + l / 2,b + l / 2,a + l / 2,b + l / 2,l / 2);
    }
    if(x > a + l / 2 - 1 && y <= b + l / 2 - 1)
    {
        cout << a + l / 2 - 1 << ' ' << b + l / 2 << ' ' << 3 << endl;
        bfs(x,y,a + l / 2,b,l / 2);
        bfs(a + l / 2 - 1,b + l / 2 - 1,a,b,l / 2);
        bfs(a + l / 2 - 1,b + l / 2,a,b + l / 2,l / 2);
        bfs(a + l / 2,b + l / 2,a + l / 2,b + l / 2,l / 2);
    }
    if(x <= a + l / 2 - 1 && y > b + l / 2 - 1)
    {
        cout << a + l / 2 << ' ' << b + l / 2 - 1 << ' ' << 2 << endl;
        bfs(a + l / 2 - 1,b + l / 2 - 1,a,b,l / 2);
        bfs(x,y,a,b + l / 2,l / 2);
        bfs(a + l / 2,b + l / 2 - 1,a + l / 2,b,l / 2);
        bfs(a + l / 2,b + l / 2,a + l / 2,b + l / 2,l / 2);
    }
    if(x > a + l / 2 - 1 && y > b + l / 2 - 1)
    {
        cout << a + l / 2 - 1 << ' ' << b + l / 2 - 1 << ' ' << 4 << endl;
        bfs(a + l / 2 - 1,b + l / 2 - 1,a,b,l / 2);
        bfs(a + l / 2,b + l / 2 - 1,a + l / 2,b,l / 2);
        bfs(a + l / 2 - 1,b + l / 2,a,b + l / 2,l / 2);
        bfs(x,y,a + l / 2,b + l / 2,l / 2);
    }
}
int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k;
    cin >> k;
    int x,y;
    cin >> x >> y;
    bfs(x,y,1,1,1 << k);
    return 0;
}