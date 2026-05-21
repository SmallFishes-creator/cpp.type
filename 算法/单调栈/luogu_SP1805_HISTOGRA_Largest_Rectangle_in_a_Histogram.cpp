#include <iostream>
#include <stack>
using namespace std;
const int N = 1e5 + 10;
int h[N];
int main()
{
    int n;
    cin >> n;
    while(n)
    {
        memset(h,0,sizeof(h));
        stack<int> st;
        for(int i = 1;i <= n;i++)
        {
            cin >> h[i];
        }
        for(int i = 0;i <= n + 1;i++)
        {
            while(!st.empty() && h[st.top()] > h[i])
                
        }
        cin >> n;
    }
    return 0;
}