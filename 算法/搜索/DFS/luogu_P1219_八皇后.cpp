#include <iostream>
using namespace std;
int n;
int idx[14];
int total;
void dfs(int count)
{
    static int tmp = 3;
    for(int i = 1;i <= n;i++)
    {
        int flag = 1;
        for(int j = 1;j < count;j++)
        {
            if(idx[j] == i || abs(count - j) == abs(i - idx[j]))
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            continue;
        idx[count] = i;
        if(count >= n)
        {
            total++;
            if(tmp > 0)
            {
                for(int k = 1;k <= n;k++)
                    cout << idx[k] << ' ';
                cout << endl;
                tmp--;
            }
            return;
        }
        dfs(count + 1);
        idx[count] = 0;
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << total << endl;
    return 0;
}