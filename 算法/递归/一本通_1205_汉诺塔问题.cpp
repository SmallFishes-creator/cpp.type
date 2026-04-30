#include <iostream>
using namespace std;
void bfs(int n,char a,char c ,char b)
{
    if(n == 0) return;
    bfs(n - 1,a,b,c);
    printf("%c->%d->%c\n",a,n,b);
    bfs(n - 1,c,a,b);
}
int main()
{
    int n;
    char a,b,c;
    cin >> n >> a >> b >> c;
    bfs(n,a,c,b);
    return 0;
}