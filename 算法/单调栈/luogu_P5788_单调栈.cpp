#include <iostream>
#include <stack>
using namespace std;
const int N = 3e6 + 10;
int arr[N];
int f[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    stack<int> st;
    for(int i = 1;i <= n;i++)
    {
        while(!st.empty() && arr[st.top()] < arr[i])
        {
            f[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        f[st.top()] = 0;
        st.pop();
    }
    for(int i = 1;i <= n;i++)
    {
        cout << f[i] << ' ';
    }
    return 0;
}