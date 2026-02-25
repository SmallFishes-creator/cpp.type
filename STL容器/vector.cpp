#include <iostream>
#include <vector>
using namespace std;
const int N = 5;
void print1(const vector<int>& a)
{
    for(int i = 0;i < a.size();i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
void print2(vector<int>& a)
{
    for(vector<int>::iterator it = a.begin();it != a.end();it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
}
void print3(vector<int>& a)
{
    for(auto it : a)
    {
        cout << it << ' ';
    }
    cout << endl;
}
int main(void)
{
    //1.vector变长数组的创建
    vector<int> a1;
    vector<vector<int>> a2;
    vector<int> a3(N);
    vector<int> a4(N,2);
    vector<char> a5(N,'*');
    vector<int> a6 = {1,2,3,4,5};
    vector<int> a7[N];
    //2.size接口
    print1(a3);
    print1(a4);
    print1(a6);
    //3.empty接口
    cout << a1.empty() << ' ' << a3.empty() << endl;
    //4.begin/end接口
    print2(a3);
    print2(a4);
    print2(a6);
    print3(a3);
    print3(a4);
    print3(a6);
    //5.push_back/pop_back接口
    a1.push_back(1);
    a1.push_back(3);
    a1.push_back(1);
    a1.push_back(4);
    a1.push_back(5);
    a1.push_back(2);
    a1.push_back(0);
    print3(a1);
    a1.pop_back();
    a1.pop_back();
    a1.pop_back();
    print3(a1);
    //6.clear接口
    cout << "before delete:" << endl;
    print3(a6);
    a6.clear();
    cout << "after delete:" << endl;
    print3(a6);
    //7.resize接口
    cout << "before change:" << endl;
    print3(a4);
    cout << "after change:" << endl;
    a4.resize(10,5);
    print3(a4);
    return 0;
}