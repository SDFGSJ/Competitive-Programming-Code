#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main(){
    int q,i;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        int op,x,c;
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&x);
            m[x]++;
        }else if(op==2){
            scanf("%d%d",&x,&c);
            m[x]-=min(c,m[x]);
            if(m[x]<=0){
                m.erase(x);
            }
        }else{
            int small=m.begin()->first;
            int big=m.rbegin()->first;
            printf("%d\n",big-small);
        }
    }
    return 0;
}