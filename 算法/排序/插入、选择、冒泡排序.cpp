#include <iostream>
using namespace std;
//插入排序
void insert_sort(int* arr,int sz)
{
    for(int i = 1;i < sz;i++)
    {
        int key = arr[i];
        int j;
        for(j = i - 1;j >= 0 && arr[j] > key;j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}
//选择排序
void select_sort(int* arr,int sz)
{
    for(int i = 0;i < sz;i++)
    {
        int min_idx = i;
        for(int j = i;j < sz;j++)
        {
            if(arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}
//冒泡排序
void bubble_sort(int* arr,int sz)
{
    for(int j = sz - 2;j >= 0;j--)
    {
        for(int i = 0;i <= j;i++)
        {
            if(arr[i] > arr[i + 1])
            {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}
int main()
{
    int arr1[] = {4,2,4,5,1};
    int arr2[] = {4,2,4,5,1};
    int arr3[] = {4,2,4,5,1};
    int sz = sizeof(arr1) / sizeof(arr1[0]);
    cout << "before sort:" << endl;
    for(int e : arr1)
    {
        cout << e << ' ';
    }
    cout << endl;
    cout << "after sort:" << endl;
    
    insert_sort(arr1,sz);
    for(int e : arr1)
    {
        cout << e << ' ';
    }
    cout << endl;

    select_sort(arr2,sz);
    for(int e : arr2)
    {
        cout << e << ' ';
    }
    cout << endl;

    bubble_sort(arr3,sz);
    for(int e : arr3)
    {
        cout << e << ' ';
    }
    cout << endl;
    return 0;
}