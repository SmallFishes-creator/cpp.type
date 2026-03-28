#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll a[N];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        unordered_map<int,int> mp;
        int left = 1;
        int right = 1;
        int ret = 0;
        while(right <= n)
        {
            mp[a[right]]++;
            while(mp[a[right]] > 1)
            {
                mp[a[left]]--;
                left++;
            }
            ret = max(ret,right - left + 1);
            right++;
        }
        cout << ret;
    }
    return 0;
}