#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
string target = "123804765";
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int bfs(string begin)
{
    queue<string> q;
    unordered_map<string,int> mp;
    q.push(begin);
    mp[begin] = 0;
    while(q.size())
    {
        string t = q.front();
        q.pop();
        if(t == target)
            return mp[t];
        int pos = t.find('0');
        int x = pos / 3;
        int y = pos % 3;
        for(int i = 0;i < 4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > 2 || ny > 2)
                continue;
            int npos = nx * 3 + ny;
            string cur = t;
            swap(cur[pos],cur[npos]);
            if(!mp.count(cur))
            {
                mp[cur] = mp[t] + 1;
                q.push(cur);
            }
        }
    }
    return -1;
}
int main()
{
    string begin;
    cin >> begin;
    cout << bfs(begin);
    return 0;
}