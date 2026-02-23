#include <iostream>
using namespace std;
typedef int elem_type;
const int N = 1000;
class sq_list
{
private:
    elem_type arr[N];
    int n;
public:
    //构造函数
    sq_list()
    {
        n = 0;
    }
    //尾插
    void push_back(elem_type e)
    {
        arr[++n] = e;
    }
    //遍历
    void print(void)
    {
        for(int i = 1;i <= n;i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    //头插
    void push_front(elem_type e)
    {
        for(int i = n;i >= 1;i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[1] = e;
        n++;
    }
    //在容易位置添加数据
    void insert_pos(int pos,elem_type e)
    {
        for(int i = n;i >= pos;i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos] = e;
        n++;
    }
};
int main()
{
    sq_list l1;
    l1.push_back(5);
    l1.push_back(2);
    l1.push_back(0);
    l1.print();
    l1.push_front(4);
    l1.push_front(1);
    l1.push_front(3);
    l1.push_front(1);
    l1.print();
    l1.insert_pos(4,0);
    l1.insert_pos(4,0);
    l1.insert_pos(4,0);
    l1.print();
    return 0;
}