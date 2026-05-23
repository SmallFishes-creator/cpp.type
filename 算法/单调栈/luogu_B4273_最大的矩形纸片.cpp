#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
using ll = long long;
const int N = 1e7 + 10;
int h[N];
int main()
{
    int n;
    cin >> n;
    memset(h,0,sizeof(h));
    ll ans = 0;
    stack<int> st;
    for(int i = 1;i <= n;i++)
    {
        cin >> h[i];
    }
    for(int i = 0;i <= n + 1;i++)
    {
        while(!st.empty() && h[st.top()] > h[i])
        {
            int height = h[st.top()];
            st.pop();
            int width = i - st.top() - 1;
            ans = max(ans,(ll)height * width);
        }
        st.push(i);
    }
    cout << ans << endl;
    return 0;
}