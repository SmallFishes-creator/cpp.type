#include <iostream>
#include <deque>
using namespace std;
const int N = 1e6 + 10;
int arr[N];
int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];
    deque<int> q;
    for(int i = 1;i <= n;i++)
    {
        while(!q.empty() && q.front() <= i - k)
            q.pop_front();
        while(!q.empty() && arr[q.back()] >= arr[i])
            q.pop_back();
        q.push_back(i);
        if(i >= k)
            cout << arr[q.front()] << ' ';
    }
    cout << endl;
    q.clear();
    for(int i = 1;i <= n;i++)
    {
        while(!q.empty() && q.front() <= i - k)
            q.pop_front();
        while(!q.empty() && arr[q.back()] <= arr[i])
            q.pop_back();
        q.push_back(i);
        if(i >= k)
            cout << arr[q.front()] << ' ';
    }
    return 0;
}