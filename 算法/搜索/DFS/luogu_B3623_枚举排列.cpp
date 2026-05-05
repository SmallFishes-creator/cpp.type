#include <iostream>
#include <vector>
using namespace std;
vector<int> path;
int cur[15];
int n,k;
void dfs()
{
    if(path.size() == k)
    {
        for(int e : path)
            cout << e << ' ';
        cout << endl;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(cur[i] == 0)
        {
            path.push_back(i);
            cur[i] = 1;
            dfs();
            cur[i] = 0;
            path.pop_back();
        }
    }
}
int main()
{
    cin >> n >> k;
    dfs();
    return 0;
}