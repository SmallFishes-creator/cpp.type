#include <iostream>
#include <string>
using namespace std;
typedef struct Tree{
    char data;
    struct Tree* left_child;
    struct Tree* right_child;
}tree;
void creat_tree(string& s,tree& T)
{
    
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    tree T;
    creat_tree(s,T);
    return 0;
}