#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int left = 0;
        for(int i = 0;i < n;i++)
        {
            char str;
            cin >> str;
            if(str == '(')
                left++;
        }
        if(2 * left == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}