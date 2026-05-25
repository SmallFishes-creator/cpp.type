#include <iostream>
#include <stack>
using namespace std;
const int N = 1e6 + 10;
int f[N];
int sz[N];
int n,m;
stack<int> st;
void Build()
{
    for(int i = 1;i <= n;i++)
    {
        f[i] = i;
        sz[i] = 1;
    }
}
int Find(int e)
{
    while(e != f[e])
    {
        st.push(e);
        e = f[e];
    }
    while(!st.empty())
    {
        f[st.top()] = e;
        st.pop();
    }
    return e;
}
bool isSameSet(int a,int b)
{
    if(Find(a) == Find(b))
        return true;
    else
        return false;
}
void Union(int a,int b)
{
    int x = Find(a);
    int y = Find(b);
    if(x == y)
        return;
    if(sz[x] >= sz[y])
    {
        sz[x] += sz[y];
        f[y] = x;
    }
    else
    {
        sz[y] += sz[x];
        f[x] = y;
    }
}
int main()
{
    cin >> n >> m;
    Build();
    while(m--)
    {
        int opt,x,y;
        cin >> opt >> x >> y;
        if(opt == 1)
        {
            if(isSameSet(x,y))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
            Union(x,y);
    }
    return 0;
}