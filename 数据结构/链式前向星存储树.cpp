#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N],e[N * 2],ne[N * 2],id = 0,n = 0;
void add(int a,int b)
{
    id++;
    e[id] = a;
    ne[id] = h[b];
    h[b] = id;
}
int main()
{
    cin >> n;
    for(int i = 1;i < n;n++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    return 0;
}