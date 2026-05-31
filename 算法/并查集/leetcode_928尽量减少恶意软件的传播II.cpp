#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
using namespace std;
vector<int> f;
vector<short> init;
vector<int> sz;
stack<int> st;
class Solution {
public:
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
    void Union(int a,int b)
    {
        int fa = find(a);
        int fb = find(b);
        if(fa == fb)
            return;
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
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) 
    {
        int n = graph.size();
        f.resize(n);
        sz.resize(n);
        init.resize(n);
        for(int i = 0;i < n;i++)
            init[i] = 0;
        for(int i = 0;i < initial.size();i++)
        {
            init[initial[i]] = 1;
        }
        for(int i = 0;i < n;i++)
        {
            f[i] = i;
            sz[i] = 1;
        }
        for(int i = 0;i < graph.size();i++)
        {
            for(int j = 0;j < graph[0].size();j++)
            {
                if(graph[i][j])
                {
                    if(init[i] == 0 && init[j] == 0)
                        Union(i,j);
                }
            }
        }
        vector<int> cnt(n,0);
        vector<vector<int>> touch(n);
        for(int i = 0;i < initial.size();i++)
        {
            int x = initial[i];
            unordered_set<int> seen;
            for(int j = 0;j < n;j++)
            {
                if(init[j] == 1)
                    continue;
                if(graph[x][j] == 1)
                {
                    seen.insert(find(j));
                }
            }
            for(int root : seen)
            {
                touch[x].push_back(root);
                cnt[root]++;
            }
        }
        sort(initial.begin(),initial.end());
        int ans = initial[0];
        int best = -1;
        for(int i = 0;i < initial.size();i++)
        {
            int x = initial[i];
            int save = 0;
            for(int j = 0;j < touch[x].size();j++)
            {
                int root = touch[x][j];
                if(cnt[root] == 1)
                {
                    save += sz[find(root)];
                }
            }
            if(save > best)
            {
                best = save;
                ans = x;
            }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> graph = {
        {1,1,0,0},
        {1,1,1,0},
        {0,1,1,1},
        {0,0,1,1}
    };
    vector<int> initial = {0,1};
    Solution s;
    cout << s.minMalwareSpread(graph, initial) << endl;
    return 0;
}