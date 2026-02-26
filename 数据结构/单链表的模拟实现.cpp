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
    list_next[head] = 0;
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
//头删
void pop_front(void)
{
    list_next[head] = list_next[list_next[head]];
}
//按位查找
int find(int pos)
{
    int p = list_next[head];
    for(int i = 0;i < pos - 1;i++)
    {
        p = list_next[p];
    }
    return p;
}
//在任意元素位置之后插入数据
void insert(int pos,elem_type e)
{
    int p = find(pos);
    id++;
    list_data[id] = e;
    list_next[id] = list_next[p];
    list_next[p] = id;
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
    push_front(2);
    print_list();
    pop_front();
    print_list();
    insert(1,8);
    print_list();
    return 0;
}