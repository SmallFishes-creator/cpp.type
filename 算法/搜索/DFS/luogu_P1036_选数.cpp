#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int n,k;
int ans;
int path;
bool isprime(int path)
{
    if(path < 2)
        return false;
    for(int i = 2;i <= path / i;i++)
    {
        if(path % i == 0)
            return false;
    }
    return true;
}
void dfs(int pos,int begin)
{
    if(pos == k)
    {
        if(isprime(path))
            ans++;
        return;
    }
    for(int i = begin;i <= n;i++)
    {
        path += arr[i];
        dfs(pos + 1,i + 1);
        path -= arr[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    arr.push_back(0);
    for(int i = 0;i < n;i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    dfs(0,1);
    cout << ans;
    return 0;
}