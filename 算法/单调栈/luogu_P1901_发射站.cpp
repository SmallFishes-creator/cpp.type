#include <iostream>
#include <stack>
using namespace std;
using PII = pair<int,int>;
using ull = unsigned long long;
const int N = 1e6 + 10;
PII arr[N];
ull f[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    //从左往右
    //先找某个数左侧最近的比他高的数的能量
    stack<int> st;
    for(int i = 1;i <= n;i++)
    {
        while(!st.empty() && arr[st.top()].first < arr[i].first)
            st.pop();
        if(!st.empty())
            f[st.top()] += arr[i].second;
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    //再找某个数右侧最近的比他高的数的能量
    for(int i = n;i >= 1;i--)
    {
        while(!st.empty() && arr[st.top()].first <= arr[i].first)
            st.pop();
        if(!st.empty())
            f[st.top()] += arr[i].second;
        st.push(i);
    }
    ull ans = 0;
    for(int i = 1;i <= n;i++)
    {
        ans = max(ans,f[i]);
    }
    cout << ans << endl;
    return 0;
}