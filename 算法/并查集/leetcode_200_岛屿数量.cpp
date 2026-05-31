#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

const int N = 1e5;
int arr[N];
int sz[N];
int record[N];
stack<int> st;

class Solution {
public:
    int find(int e)
    {
        while(e != arr[e])
        {
            st.push(e);
            e = arr[e];
        }
        while(!st.empty())
        {
            arr[st.top()] = e;
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
        if(sz[fa] <= sz[fb])
        {
            arr[fa] = fb;
            sz[fb] += sz[fa];
        }
        else
        {
            arr[fb] = fa;
            sz[fa] += sz[fb];
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(arr,0,sizeof arr);
        const int row = grid.size();
        const int col = grid[0].size();
        int n = row * col;
        for(int i = 0;i < n;i++)
        {
            arr[i] = i;
            sz[i] = 1;
            record[i] = 0;
        }
        for(int i = 0;i < row;i++)
        {
            for(int j = 0;j < col;j++)
            {
                if(i + 1 < row && grid[i][j] == '1' && grid[i + 1][j] == '1')
                {
                    Union(i * col + j,(i + 1) * col + j);
                }
                if(j + 1 < col && grid[i][j] == '1' && grid[i][j + 1] == '1')
                {
                    Union(i * col + j,i * col + j + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < row;i++)
        {
            for(int j = 0;j < col;j++)
            {
                if(grid[i][j] == '1' && record[find(i * col + j)] == 0)
                {
                    record[find(i * col + j)] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    Solution s;
    int ans = s.numIslands(grid);
    cout << ans << endl;
    return 0;
}