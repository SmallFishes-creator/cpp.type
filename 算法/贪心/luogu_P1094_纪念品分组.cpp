#include <iostream>
#include <algorithm>
const int N = 1e5 + 10;
int arr[N];
using namespace std;
int main()
{
    int w,n;
    cin >> w >> n;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];
    sort(arr + 1,arr + 1 + n);
    int left = 1;
    int right = n;
    int ret = 0;
    while(left < right)
    {
        if(arr[left] + arr[right] <= w)
            left++;
        ret++;
        right--;
    }
    if(left == right)
        ret++;
    cout << ret;
    return 0;
}