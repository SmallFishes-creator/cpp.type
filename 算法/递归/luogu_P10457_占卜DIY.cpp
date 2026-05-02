#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> arr[20];
int record[20] = {4};
void recur(int num)
{
    if(num == 13) return;
    arr[num].push(num);
    int cur = arr[num].front();
    arr[num].pop();
    record[num]--;
    recur(cur);
}
int main()
{
    for(int i = 1;i <= 13;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            int tmp;
            cin >> tmp;
            switch(tmp)
            {
            case 0:
                tmp = 10;
                break;
            case 'A':
                tmp = 1;
                break;
            case 'J':
                tmp = 11;
                break;
            case 'Q':
                tmp = 12;
                break;
            case 'K':
                tmp = 13;
                break;
            }
            arr[i].push(tmp);
        }
    }
    while(record[13])
    {
        int num = arr[13].front();
        arr[13].pop();
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