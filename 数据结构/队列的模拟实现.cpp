#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int queue[N];
int f = 0;
int t = 0;
//入队
void push(int e)
{
    queue[++t] = e;
}
//出队
void pop(void)
{
    f++;
}
//队头元素
int front()
{
    return queue[f + 1];
}
//队尾元素
int back()
{
    return queue[t];
}
//元素个数
int size()
{
    return t - f;
}
int main()
{
    push(1);
    push(3);
    push(1);
    push(4);
    push(5);
    push(2);
    push(0);
    while(size())
    {
        cout << front() << ' ';
        pop();
    }
    cout << endl;
    return 0;
}