#include<bits/stdc++.h>
using namespace std;
int a[15][15],c[15];
int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    int ans=INT_MAX;
    for(int mask=0;mask<(1<<n);mask++){
        int cost[15]={},cur=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){    //buy the i-th book
                cur+=c[i];
                for(int j=0;j<m;j++){
                    cost[j]+=a[i][j];
                }
            }
        }

        bool ok=true;
        for(int i=0;i<m;i++){
            if(cost[i]<x){
                ok=false;
            }
        }
        if(ok){
            ans=min(ans,cur);
        }
    }
    if(ans==INT_MAX){
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
bit enumeration
buy or dont buy a book
*/