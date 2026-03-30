#include <iostream>
#include <climits>
using namespace std;
const int N1 = 1e6 + 10;
const int N2 = 2e3 + 10;
int a[N1];//画
int record[N2];//大师
int main()
{
    int n,m;
    cin >> n >> m;            
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int left = 1,right = 1,ret = INT_MAX,count = 0,x,y;
    while(right <= n)
    {
        if(record[a[right]] == 0)
            count++;
        record[a[right]]++;
        while(count == m && record[a[left]] > 1)
        {
            record[a[left]]--;
            left++;
        }
        if(count == m && ret > right - left + 1)
        {
            ret = right - left + 1;
            x = left;
            y = right;
        }
        right++;
    }
    cout << x << ' ' << y;
    return 0;
}