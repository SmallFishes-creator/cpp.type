#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ull = unsigned long long;
bool cmp(string e1,string e2)
{
    return e1 + e2 > e2 + e1;
}
int main()
{
    vector<string> arr;
    int n;
    cin >> n;
    while(n--)
    {
        string a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end(),cmp);
    for(string e : arr)
    {
        cout << e;
    }
    return 0;
}