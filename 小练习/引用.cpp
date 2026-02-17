#include <iostream>
using namespace std;
int main(void)
{
    int a = 1314520;
    int& b = a;
    printf("a -adress: %p\n",&a);
    printf("b -adress: %p\n",&b);
    cout << a << endl;
    b = 1314000;
    cout << a << endl;
    return 0;
}
