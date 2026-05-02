#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 10;
typedef struct record{
    int c;
    int num;
    int flag;
}R;
R arr[N];
int r_c[N][2];
int off_r;
int off_c;
int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 1;i <= q;i++)
    {
        string s1,s2;
        int cur;
        cin >> s1 >> cur >> s2;
        if(s1 == "row")
            arr[i].c = 0;
        else
            arr[i].c = 1;
        arr[i].num = cur;
        if(s2 == "on")
            arr[i].flag = 1;
        else
            arr[i].flag = 0;
    }
    int total = 0;
    for(int i = q;i >= 1;i--)
    {
        if(r_c[arr[i].num][arr[i].c] == 0)
        {
            r_c[arr[i].num][arr[i].c] = 1;
            if(arr[i].flag == 1)
            {
                if(arr[i].c == 0) total += (m - off_c);
                else total += (n - off_r);
            }
            if(arr[i].c == 0) off_r++;
            else off_c++;
        }
    }
    cout << total;
    return 0;
}