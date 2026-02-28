//vector存储版
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> edges[N];
bool judge[N] = {false};
void DFS(int num)
{
    cout << num << ' ';
    judge[num] = true;
    for(auto e :edges[num])
    {
        if(!judge[e])
        {
            DFS(e);
        }
    }
}
int main()
{
    int n = 0;
    cin >> n;
    for(int i = 1;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    DFS(1);
    return 0;
}