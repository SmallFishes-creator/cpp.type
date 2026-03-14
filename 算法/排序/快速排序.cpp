#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
vector<int> arr;
int n;
int get_random(int left,int right)
{
    return arr[rand() % (right - left + 1) + left];
}
void quick_sort(int left,int right)
{
    if(left >= right)
        return;
    int p = get_random(left,right);
    int l = left - 1;
    int i = left;
    int r = right + 1;
    while(i < r)
    {
        if(arr[i] < p)
            swap(arr[i++],arr[++l]);
        else if(arr[i] == p)
            i++;
        else
            swap(arr[i],arr[--r]);
    }
    quick_sort(left,l);
    quick_sort(r,right);
}
int main()
{
    srand(time(NULL));
    cin >> n;
    arr.resize(n);
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
    }
    cout << "before sort:" << endl;
    for(int e : arr)
    {
        cout << e << ' ';
    }
    cout << endl;
    quick_sort(0,n - 1);
    cout << "after sort:" << endl;
    for(int e : arr)
    {
        cout << e << ' ';
    }
    cout << endl;
    return 0;
}