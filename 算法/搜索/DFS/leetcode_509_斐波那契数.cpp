#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
    int f[35];
public:
    int dfs(int n)
    {
        if(f[n] != -1) return f[n];
        f[n] = dfs(n - 1) + dfs(n - 2);
        return f[n];
    }
    int fib(int n) {
        fill(f,f + 34,-1);
        f[0] = 0;
        f[1] = 1;
        return dfs(n);
    }
};
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.fib(n) << endl;
}