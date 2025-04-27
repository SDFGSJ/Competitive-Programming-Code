#include<bits/stdc++.h>
using namespace std;
bool all[200010];   //all[i] = true if user i can view all contest pages
set<int> canread[200010];   //canread[i] = list of pages user i can read
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    while(q--){
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1){
            int y;
            scanf("%d",&y);
            canread[x].emplace(y);
        }else if(op==2){
            all[x]=true;
        }else{
            int y;
            scanf("%d",&y);
            if(all[x] || canread[x].find(y)!=canread[x].end()){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}
/*
binary search
*/