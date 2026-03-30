#include <iostream>
#include <climits>
#include <string>
const int N = 30;
using namespace std;
int main()
{
    string s;
    cin >> s;
    int left = 0,right = 0,ret = INT_MAX,count = 0,arr[N] = {0};
    while(right < s.size())
    {
        if(arr[s[right] - 'a'] == 0)
            count++;
        arr[s[right] - 'a']++;
        while(count == 26 && arr[s[left] - 'a'] > 1)
        {
            arr[s[left] - 'a']--;
            left++;
        }
        if(count == 26)
            ret = min(ret,right - left + 1);
        right++;
    }
    cout << ret;
    return 0;
}