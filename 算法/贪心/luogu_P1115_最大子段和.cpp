#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    ll ret = -1e6;
    ll sum = 0;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
        ret = max(ret,sum);
        if(sum < 0)
            sum = 0;
    }
    cout << ret;
    return 0;
}