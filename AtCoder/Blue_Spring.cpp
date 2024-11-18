#include<bits/stdc++.h>
using namespace std;
int cost[200010];
int main(){
    int n,d,p;
    scanf("%d%d%d",&n,&d,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&cost[i]);
    }
    sort(cost,cost+n);

    long long ans=0,tmp=0;
    for(int i=n-1,cnt=1;i>=0;i--,cnt++){
        tmp+=cost[i];
        if(cnt%d==0){   //sum of cost over d consecutive days
            ans+=min(1ll*p,tmp);
            tmp=0;
        }
    }
    ans+=min(1ll*p,tmp);    //check whether one-day pass is cheaper to cover the remaining days
    printf("%lld\n",ans);
    return 0;
}
/*
sort F[] asc, use one-day pass on expensive days(start from the back)
if using one-day pass is cheaper over d consecutive days, then use it
*/