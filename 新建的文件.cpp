#include <bits/stdc++.h>
struct Node{
    int lpos = -1;
    int rpos = -1;
};
Node tree[30];
int letter[30];
bool isNotRoot[30];
bool vis[30];
char s [5];
using namespace std;


void build(int input_letter,int l,int r){
    vis[input_letter] = 1;
    if( l >= 0){
        vis[l] = true;
        tree[input_letter].lpos = l;
        isNotRoot[l] = 1;
    }
    if(r >= 0){
        vis[r] = true;
        tree[input_letter].rpos = r;
        isNotRoot[r] = 1;
    }
}
void PreorderTraversal(int i){ //前序遍历
    if(i < 0) return;
    printf("%c",char(i+'a'));
    PreorderTraversal(tree[i].lpos);
    PreorderTraversal(tree[i].rpos);
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++){
        scanf("%s",&s);
        build(s[0]-'a',s[1]-'a',s[2]-'a');

    }
    //前序遍历！！
    for(int i = 0; i <= 27; i ++ ){
        if(vis[i] && !isNotRoot[i]){
            PreorderTraversal(i);
            break;
        }
    }
    //
    return 0;
}
