#include<bits/stdc++.h>
using namespace std;
long long a[200010],add[200010];
set<long long> added_idx;   //set of idxes of op type 2
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    int q,all=-1;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int xq;
            scanf("%d",&xq);
            all=xq;
            for(auto idx:added_idx){    //only reset those who were added before
                add[idx]=0;
            }
            added_idx.clear();
        }else if(op==2){
            int iq,xq;
            scanf("%d%d",&iq,&xq);
            add[iq]+=xq;
            added_idx.emplace(iq);  //remember who has been added
        }else{
            int iq;
            scanf("%d",&iq);
            if(all==-1){
                printf("%lld\n",a[iq]+add[iq]);
            }else{
                printf("%lld\n",all+add[iq]);
            }
        }
    }
    return 0;
}