#include <iostream>
#include <stack>
using namespace std;
const int N = 1e6 + 10;
int f[N];
int sz[N];
stack<int> st;
int n,m;
void Build()
{
    for(int i = 1;i <= n;i++)
    {
        f[i] = i;
        sz[i] = 1;
    }
}
int find(int e)
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
    if(find(a) == find(b))
        return true;
    else
        return false;
}
void Union(int a,int b)
{
    if(find(a) == find(b))
        return;
    int fa = find(a);
    int fb = find(b);
    if(sz[fa] >= sz[fb])
    {
        f[fb] = fa;
        sz[fa] += sz[fb];
    }
    else
    {
        f[fa] = fb;
        sz[fb] += sz[fa];
    }
}
int main()
{
    cin >> n >> m;
    Build();
    while(m--)
    {
        int z,x,y;
        cin >> z >> x >> y;
        if(z == 1)
        {
            Union(x,y);
        }
        else
        {
            if(isSameSet(x,y))
                cout << 'Y' << endl;
            else
                cout << 'N' << endl;
        }
    }
    return 0;
}