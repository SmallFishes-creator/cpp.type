#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 35;
int f[N];
int sz[N];
stack<int> st;

class Solution {
public:
    int find(int e)
    {
        while(e != f[e])
        {
            e = f[e];
            st.push(e);
        }
        while(!st.empty())
        {
            f[st.top()] = e;
            st.pop();
        }
        return e;
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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        for(int i = 0;i < n;i++)
        {
            f[i] = i;
            sz[i] = 1;
        }
        for(int i = 0;i < row.size();i += 2)
        {
            int a = row[i];
            int b = row[i + 1];
            if(a / 2 != b / 2)
                Union(a / 2,b / 2);
        }
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            if(find(i) == i)
                ans++;
        }
        return n - ans;
    }
};
int main()
{
    vector<int> row = {
        0, 2, 1, 3
    };
    Solution s;
    int ans = s.minSwapsCouples(row);
    cout << ans << endl;
    return 0;
}