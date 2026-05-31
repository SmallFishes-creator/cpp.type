#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

const int N = 310;
int f[N];
int sz[N];
int record[N];
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
        if(find(a) == find(b))
            return;
        int fa = find(a);
        int fb = find(b);
        if(fa >= fb)
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
    int numSimilarGroups(vector<string>& strs) {
        for(int i = 0;i < strs.size();i++)
        {
            f[i] = i;
            sz[i] = 1;
            record[i] = 0;
        }
        for(int i = 0;i < strs.size();i++)
        {
            string s1 = strs[i];
            for(int j = i + 1;j < strs.size();j++)
            {
                string s2 = strs[j];
                int count = 0;
                for(int k = 0;k < strs[0].size();k++)
                {
                    if(s1[k] != s2[k])
                        count++;
                }
                if(count == 0 || count == 2)
                    Union(i,j);
            }
        }
        int ans = 0;
        for(int i = 0;i < strs.size();i++)
        {
            if(record[find(i)] == 1)
                continue;
            ans++;
            record[find(i)] = 1;
        }
        return ans;
    }
};
int main()
{
    vector<string> strs = {
        "tars",
        "rats",
        "arts",
        "star"
    };
    Solution s;
    int ans = s.numSimilarGroups(strs);
    cout << ans << endl;
    return 0;
}