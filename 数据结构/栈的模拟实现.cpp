#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int stack[N];
int n = 0;
//入栈
void push(int e)
{
    stack[++n] = e;
}
//出栈
void pop()
{
    n--;
}
//获取栈顶元素
int top()
{
    return stack[n];
}
//元素个数
int size()
{
    return n;
}
int main()
{
    push(1);
    push(3);
    push(1);
    push(4);
    while(size())
    {
        cout << stack[n] << ' ';
        pop();
    }
    return 0;
}