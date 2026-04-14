#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        if(x > arr[n - 1] || y < arr[0])
        {
            cout << 0 << endl;
            continue;
        }
        int left = 0;
        int right = n - 1;
        if(arr[left] < x)
        {
            while(left < right)
            {
                int mid = (left + right) / 2;
                if(arr[mid] >= x) right = mid;
                else left = mid + 1;
            }
        }
        int retleft = left;
        left = 0;       
        right = n - 1;
        if(arr[right] > y)
        {
            while(left < right)
            {
                int mid = (left + right + 1) / 2;
                if(arr[mid] <= y) left = mid;
                else right = mid - 1;
            }
        }
        int retright = right;
        int total = retright - retleft + 1;
        cout << total << endl;
    }
    return 0;
}