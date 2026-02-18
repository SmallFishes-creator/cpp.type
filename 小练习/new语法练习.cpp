#include <iostream>
using namespace std;
int main()
{
    int a = 3141520;
    int* p = new int(a);
    cout << *p << endl;
    delete p;
    cout << *p << endl;
    int* arr = new int[10];
    for(int i = 0;i < 10;i++)
    {
        arr[i] = i + 100;
    }
    for(int i = 0;i < 10;i++)
    {
        cout << arr[i] <<' ';
    }
    cout << endl;
    return 0;
}