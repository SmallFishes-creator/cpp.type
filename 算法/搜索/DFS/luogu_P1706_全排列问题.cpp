#include <iostream>
#include <vector>
using namespace std;
vector<int> path;
int cur[10];
int n;
void dfs()
{
    if(path.size() == n)
    {
        for(int e : path)
            printf("%5d",e);
        cout << endl;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!cur[i])
        {
            path.push_back(i);
            cur[i] = 1;
            dfs();
            path.pop_back();
            cur[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs();
    return 0;
}