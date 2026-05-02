#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
deque<int> arr[20];
int record[20];
void recur(int num)
{
    if(num == 13) return;
    int cur = arr[num].front();
    arr[num].pop_front();
    record[num]--;
    recur(cur);
}
int main()
{
    fill(record + 1,record + 21,4);
    for(int i = 1;i <= 13;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            int cur = 0;
            char tmp;
            cin >> tmp;
            switch(tmp)
            {
            case '0':
                cur = 10;
                break;
            case 'A':
                cur = 1;
                break;
            case 'J':
                cur = 11;
                break;
            case 'Q':
                cur = 12;
                break;
            case 'K':
                cur = 13;
                break;
            default:
                cur = tmp - '0';
            }
            arr[i].push_front(cur);
        }
    }
    while(record[13])
    {
        int num = arr[13].back();
        arr[13].pop_back();
        record[13]--;
        recur(num);
    }
    int total = 0;
    for(int i = 1;i < 13;i++)
    {
        if(record[i] == 0)
            total++;
    }
    cout << total;
    return 0;
}