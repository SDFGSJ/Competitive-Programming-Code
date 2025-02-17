#include<bits/stdc++.h>
using namespace std;
int nxt[100010],prv[100010];
int get_head(int x){    //find the head of the component where x belongs to
    while(prv[x]!=-1){
        x=prv[x];
    }
    return x;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++){
        nxt[i]=prv[i]=-1;
    }

    while(q--){
        int op,x,y;
        scanf("%d%d",&op,&x);
        if(op==1){  //x->y and x<-y
            scanf("%d",&y);
            nxt[x]=y;prv[y]=x;
        }else if(op==2){    //x->NULL and NULL<-y
            scanf("%d",&y);
            nxt[x]=prv[y]=-1;
        }else{
            int head=get_head(x);
            vector<int> ans;
            while(head!=-1){
                ans.emplace_back(head);
                head=nxt[head];
            }
            printf("%ld ",ans.size());
            for(auto num:ans){
                printf("%d ",num);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
linked list using nxt,prv
use -1 as dummy node
*/