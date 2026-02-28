//链式前向星存储版
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int h[N],e[N * 2],ne[N * 2],id = 0,n = 0;
bool judge[N] = {false};
void add(int a,int b)
{
    id++;
    e[id] = a;
    ne[id] = h[b];
    h[b] = id;
}
void BFS(int num)
{
    queue<int> q;
    q.push(num);
    judge[num] = true;
    while(q.size())
    {
        int x = q.front();
        cout << x << ' ';
        q.pop();
        for(int i = h[x];i;i = ne[i])
        {
            int y = e[i];
            if(!judge[y])
            {
                q.push(y);
                judge[y] = true;
            }
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    BFS(1);
    return 0;
}