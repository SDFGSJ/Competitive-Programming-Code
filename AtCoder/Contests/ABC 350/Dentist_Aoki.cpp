#include<bits/stdc++.h>
using namespace std;
int holes[1005];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    int ans=n;
    for(int i=0;i<q;i++){
        int t;
        scanf("%d",&t);
        if(!holes[t]){
            holes[t]=1;
            ans--;
        }else{
            holes[t]=0;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}