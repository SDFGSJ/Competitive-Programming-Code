#include<bits/stdc++.h>
using namespace std;
int a[100010];
long long diff[100010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    long long ans=0;
    for(int i=1;i+1<=n;i++){
        diff[i]=a[i+1]-a[i];
        ans+=abs(diff[i]);
    }

    for(int i=0;i<q;i++){
        int l,r,v;
        scanf("%d%d%d",&l,&r,&v);
        long long before=abs(diff[l-1])+abs(diff[r]);
        if(l-1>=1){
            diff[l-1]+=v;
        }
        if(r<=n-1){
            diff[r]-=v;
        }
        long long after=abs(diff[l-1])+abs(diff[r]);
        ans+=after-before;
        printf("%lld\n",ans);
    }
    return 0;
}
/*
height changes only happens at l-1,r
a[l]+v => diff[l-1] = a[l]-a[l-1] = (a[l]+v) - a[l-1] = diff[l-1] + v
a[r]+v => diff[r] = a[r+1]-a[r] = a[r+1]-(a[r]+v) = diff[r] - v
*/