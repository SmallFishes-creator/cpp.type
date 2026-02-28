//链式前向星储存
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N],e[N * 2],ne[N * 2],judge[N] = {false},id = 0,n = 0;
void add(int a,int b)
{
    id++;
    e[id] = a;
    ne[id] = h[b];
    h[b] = id;
}
void DFS(int num)
{
    cout << num << ' ';
    judge[num] = true;
    for(int i = h[num];i;i = ne[i])
    {
        int x = e[i];
        if(!judge[x])
        {
            DFS(x);
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
    DFS(1);
    return 0;
}