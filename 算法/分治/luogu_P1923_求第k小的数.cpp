#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 5e6 + 10;
int arr[N];
int quick_select(int left,int right,int k)
{
    while(left < right)
    {
        int idx = left + rand() % (right - left + 1);
        int value = arr[idx];
        swap(arr[idx],arr[right]);
        int i = left;
        for(int j = left;j < right;j++)
        {
            if(arr[j] <= value)
            {
                swap(arr[i],arr[j]);
                i++;
            }
        }
        swap(arr[i],arr[right]);
        if(i == k)
            return arr[i];
        else if(i > k)
            right = i - 1;
        else
            left = i + 1;
    }
    return arr[left];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    srand(time(NULL));
    cout << quick_select(0,n - 1,k) << endl;
    return 0;
}