#include <iostream>
#include <string>
using namespace std;
typedef struct Tree{
    char data;
    struct Tree* left_child;
    struct Tree* right_child;
}tree;
typedef tree* bi_tree;
void creat_tree(string& s,bi_tree* T,int l,int r)
{
    *T = new tree;
    int flag0 = 0;
    int flag1 = 0;
    for(int i = l;i <= r;i++)
    {
        if(s[i] == '0')
            flag0 = 1;
        else
            flag1 = 1;
        if(flag0 && flag1)
            break;
    }
    if(flag0 == 1 && flag1 == 1)
        (*T)->data = 'F';
    else if(flag0 == 1)
        (*T)->data = 'B';
    else if(flag1 == 1)
        (*T)->data = 'I';
    if(l == r)
    {
        (*T)->left_child = NULL;
        (*T)->right_child = NULL;
        return;
    }
    int m = (l + r) / 2;
    creat_tree(s,&(*T)->left_child,l,m);
    creat_tree(s,&(*T)->right_child,m + 1,r);
}
void print(bi_tree T)
{
    if(T == NULL)
        return;
    print((T->left_child));
    print((T->right_child));
    cout << T->data;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bi_tree T = NULL;
    int left = 0;
    int right = s.size() - 1;
    creat_tree(s,&T,left,right);
    print(T);
    return 0;
}