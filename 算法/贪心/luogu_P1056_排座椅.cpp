#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using PII = pair<int,int>;
const int N = 1e3 + 10;
//行 row
//列 col
int r[N];
int c[N];
bool cmp(PII e1,PII e2)
{
    return e1.second > e2.second;
}
int main()
{
    int m,n,k,l,d;
    cin >> m >> n >> k >> l >> d;
    for(int i = 1;i <= d;i++)
    {
        int x,y,p,q;
        cin >> x >> y >> p >> q;
        //行相同
        if(x == p)
            c[min(y,q)]++;
        //列相同
        if(y == q)
            r[min(x,p)]++;
    }
    vector<PII> col;
    vector<PII> row;
    for(int i = 1;i <= n;i++)
    {
        col.push_back({i,c[i]});
    }
    for(int i = 1;i <= m;i++)
    {
        row.push_back({i,r[i]});
    }
    sort(row.begin(),row.end(),cmp);
    sort(col.begin(),col.end(),cmp);
    vector<pair<int,int>> row_ret;
    vector<pair<int,int>> col_ret;
    for(int i = 0;i < k;i++)
    {
        row_ret.push_back(row[i]);
    }
    for(int i = 0;i < l;i++)
    {
        col_ret.push_back(col[i]);
    }
    sort(row_ret.begin(),row_ret.end());
    sort(col_ret.begin(),col_ret.end());
    for(int i = 0;i < k;i++)
    {
        cout << row_ret[i].first <<(i < k - 1 ? " " : "");
    }
    cout << endl;
    for(int i = 0;i < l;i++)
    {
        cout << col_ret[i].first <<(i < l - 1 ? " " : "");
    }
    return 0;
}