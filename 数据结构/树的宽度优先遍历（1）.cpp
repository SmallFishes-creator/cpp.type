//vector数组存储版
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> edges[N];
bool judge[N] = {false};
void BFS(int num)
{
    queue<int> q;
    q.push(num);
    judge[num] = true;
    while(q.size())
    {
        int u = q.front();
        cout << u << ' ';
        q.pop();
        for(auto e : edges[u])
        {
            if(!judge[e])
            {
                q.push(e);
                judge[e] = true;
            }
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
    BFS(1);
    return 0;
}