#include<bits/stdc++.h>
using namespace std;
int q[105],r[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&q[i],&r[i]);
    }

    int que;
    scanf("%d",&que);
    while(que--){
        int t,d;
        scanf("%d%d",&t,&d);
        int mod=d%q[t],ans=0;
        if(mod<=r[t]){  //(r[t]-mod) days later
            ans=d+r[t]-mod;
        }else{  //add (q[t]-mod) days to become multiple of q[t], then wait another r[t] days
            ans=d+q[t]-mod+r[t];
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
simulation + modular
*/