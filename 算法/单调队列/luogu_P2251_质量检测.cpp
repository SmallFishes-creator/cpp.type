#include <iostream>
#include <deque>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];
    deque<int> q;
    for(int i = 1;i <= n;i++)
    {
        while(!q.empty() && q.front() <= i - m)
            q.pop_front();
        while(!q.empty() && arr[q.back()] >= arr[i])
            q.pop_back();
        q.push_back(i);
        if(i >= m)
            cout << arr[q.front()] << endl;
    }
    return 0;
}