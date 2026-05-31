#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int f[N];
stack<int> st;

class Solution {
public:
    static bool cmp(vector<int>& e1,vector<int>& e2)
    {
        return e1[2] < e2[2];
    }
    int find(int e)
    {
        while(f[e] != e)
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
    void Union(int e1,int e2)
    {
        if(find(e1) == find(e2))
            return;
        f[find(e1)] = find(e2);
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for(int i = 0;i < n;i++)
        {
            f[i] = i;
        }
        Union(firstPerson,0);
        sort(meetings.begin(),meetings.end(),cmp);
        int time = meetings[0][2];
        stack<int> person;
        for(int i = 0;i < meetings.size();i++)
        {
            if(meetings[i][2] == time)
            {
                person.push(meetings[i][0]);
                person.push(meetings[i][1]);
                Union(meetings[i][0],meetings[i][1]);
            }
            else
            {
                while(!person.empty())
                {
                    if(find(person.top()) != find(0))
                    {
                        f[person.top()] = person.top();
                    }
                    person.pop();
                }
                time = meetings[i][2];
                person.push(meetings[i][0]);
                person.push(meetings[i][1]);
                Union(meetings[i][0],meetings[i][1]);
            }
        }
        vector<int> ans;
        for(int i = 0;i < n;i++)
        {
            if(find(i) == find(0))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    int n = 6;

    vector<vector<int>> meetings = {
        {1, 2, 5},
        {2, 3, 8},
        {1, 5, 10}
    };
    int firstPerson = 1;
    Solution s;
    vector<int> ans = s.findAllPeople(n, meetings, firstPerson);
    for(int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}