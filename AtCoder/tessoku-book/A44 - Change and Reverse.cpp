#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        a[i]=i;
    }

    int reversed=0;
    while(q--){
        int op,x,y;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&y);
            if(!reversed){
                a[x]=y;
            }else{
                a[n+1-x]=y;
            }
        }else if(op==2){
            reversed^=1;
        }else{
            scanf("%d",&x);
            if(!reversed){
                printf("%d\n",a[x]);
            }else{
                printf("%d\n",a[n+1-x]);
            }
        }
    }
    return 0;
}