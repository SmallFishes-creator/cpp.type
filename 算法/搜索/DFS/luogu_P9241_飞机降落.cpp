#include <iostream>
#include <vector>
using namespace std;
typedef struct Plane{
    int T;
    int D;
    int L;
}plane;
bool dfs(vector<plane>& arr,int count,int n,int* record,int time)
{
    if(count > n)
    {
        return true;
    }
    for(int i = 0;i < arr.size();i++)
    {
        if(record[i] == 1)
            continue;
        int start_time = max(time,arr[i].T);
        if(start_time > arr[i].T + arr[i].D)
            continue;
        record[i] = 1;
        if(dfs(arr,count + 1,n,record,start_time + arr[i].L))
            return true;
        record[i] = 0;
    }
    return false;
}
int main()
{
    int M;
    cin >> M;
    while(M--)
    {
        int n;
        cin >> n;
        vector<plane> arr;
        int* record = new int[n]();
        for(int i = 0;i < n;i++)
        {
            int t,d,l;
            cin >> t >> d >> l;
            arr.push_back({t,d,l});
        }
        if(dfs(arr,1,n,record,0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        delete[] record;
    }
    return 0;
}