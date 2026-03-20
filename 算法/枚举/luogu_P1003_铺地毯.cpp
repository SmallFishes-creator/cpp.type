#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int a[N],b[N],g[N],k[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    int x,y;
    cin >> x >> y;
    int flag = 0;
    for(int i = n - 1;i >= 0;i--)
    {
        if(x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i])
        {
            cout << i + 1;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout << -1;
    }
    return 0;
}