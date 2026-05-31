#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

const int N = 1e3 + 10;
unordered_map<int,int> row;
unordered_map<int,int> col;
int f[N];
int sz[N];
stack<int> st;

class Solution {
public:
    int find(int e)
    {
        while(f[e] != e)
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
    bool Union(int a,int b)
    {
        if(find(a) == find(b))
            return true;
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
        return false;
    }
    int removeStones(vector<vector<int>>& stones) {
        row.clear();
        col.clear();
        int len = stones.size();
        for(int i = 0;i < len;i++)
        {
            f[i] = i;
            sz[i] = 1;
        }
        int ans = 0;
        for(int i = 0;i < len;i++)
        {
            if(row.find(stones[i][0]) != row.end())
            {
                if(!Union(row[stones[i][0]],i))
                    ans++;
            }
            else
                row.insert({stones[i][0],i});
            if(col.find(stones[i][1]) != col.end())
            {
                if(!Union(col[stones[i][1]],i))
                    ans++;
            }
            else
                col.insert({stones[i][1],i});
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> stones = {{0, 0},{0, 1},{1, 0},{1, 2},{2, 1},{2, 2}};
    Solution s;
    int ans = s.removeStones(stones);
    cout << ans << endl;
    return 0;
}