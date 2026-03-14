#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<int> tmp;
void merge_sort(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    int cur1 = left;
    int cur2 = mid + 1;
    int i = left;
    while (cur1 <= mid && cur2 <= right)
    {
        if (arr[cur1] <= arr[cur2])
            tmp[i++] = arr[cur1++];
        else
            tmp[i++] = arr[cur2++];
    }
    while (cur1 <= mid)
        tmp[i++] = arr[cur1++];
    while (cur2 <= right)
        tmp[i++] = arr[cur2++];
    for (int i = left; i <= right; i++)
    {
        arr[i] = tmp[i];
    }
}
int main()
{
    int n;
    cin >> n;
    arr.resize(n + 1);
    tmp.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << "before sort:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    merge_sort(1, n);
    cout << "after sort:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}