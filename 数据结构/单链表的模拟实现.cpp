#include <iostream>
using namespace std;
typedef int elem_type;
const int N = 1e5;
elem_type list_data[N];
int list_next[N];
int head,id;
//初始化
void initial()
{
    head = 0;
    list_next[head] = -1;
    id = 0;
}
//头插
void push_front(elem_type e)
{
    id++;
    list_data[id] = e;
    list_next[id] = list_next[head];
    list_next[head] = id;
}
//遍历
void print_list(void)
{
    for(int i = list_next[head];i;i = list_next[i])
    {
        cout << list_data[i] << ' ';
    }
    cout << endl;
}
int main()
{
    initial();
    push_front(0);
    push_front(2);
    push_front(5);
    print_list();
    return 0;
}