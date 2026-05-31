#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> f;
vector<int> sz;
vector<unordered_map<int,int>> cnt;
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
    static bool cmp(vector<int>& e1,vector<int>& e2)
    {
        return e1[2] < e2[2];
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        f.clear();
        sz.clear();
        cnt.clear();
        int n = vals.size();
        f.resize(n);
        sz.resize(n);
        cnt.resize(n);
        for(int i = 0;i < n;i++)
        {
            f[i] = i;
            sz[i] = 1;
            cnt[i][vals[i]] = 1;
        }
        int ans = n;
        for(int i = 0;i < edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            edges[i].push_back(max(vals[a],vals[b]));
        }
        sort(edges.begin(),edges.end(),cmp);
        for(int i = 0;i < edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int fa = find(a);
            int fb = find(b);
            if(fa == fb)
                continue;
            int Max = edges[i][2];
            int countA = cnt[fa][Max];
            int countB = cnt[fb][Max];
            ans += countA * countB;
            if(sz[fa] < sz[fb])
                swap(fa,fb);
            f[fb] = fa;
            sz[fa] += sz[fb];
            for(auto& e : cnt[fb])
            {
                int val = e.first;
                int num = e.second;
                cnt[fa][val] += num;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> vals = {1, 3, 2, 1, 3};
    vector<vector<int>> edges = {{0, 1},{0, 2},{2, 3},{2, 4}};
    Solution s;
    int ans = s.numberOfGoodPaths(vals, edges);
    cout << ans << endl;
    return 0;
}