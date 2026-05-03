#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int judge[5] ={0};
int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];
    int left = 1;
    int right = 1;
    int len = 1e6;
    while(right <= n)
    {
        judge[arr[right]]++;
        int flag = 0;
        while(flag == 0)
        {
            for(int i = 1;i <= 4;i++)
            {
                if(i == 4 && judge[i] < k)
                {
                    flag = 1;
                    break;
                }
                else if(i != 4 && judge[i] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
            judge[arr[left]]--;
            len = min(len,right - left + 1);
            left++;
        }
        right++;
    }
    cout << len;
    return 0;
}