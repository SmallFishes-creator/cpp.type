#include <iostream>
#include <vector>
using namespace std;
void down(vector<int>& arr,int parent,int len)
{
    int children = parent * 2 + 1;
    while(children <= len - 1)
    {
        if(children + 1 <= len - 1 && arr[children + 1] > arr[children])
            children++;
        if(arr[parent] >= arr[children])
            return;
        swap(arr[parent],arr[children]);
        parent = children;
        children = parent * 2 + 1;
    }
}
void heap_sort(vector<int>& arr,int n)
{
    //建立大根堆
    for(int i = n / 2 - 1;i >= 0;i--)
    {
        //调整
        down(arr,i,n);
    }
    //排序
    for(int i = n - 1;i >= 0;i--)
    {
        swap(arr[i],arr[0]);
        down(arr,0,i);
    }
}
int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
    }
    cout << "before sort:" << endl;
    for(int i = 0;i < n;i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    heap_sort(arr,n);
    //打印
    cout << "after sort:" << endl;
    for(int i = 0;i < n;i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}