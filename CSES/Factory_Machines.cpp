#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
bool ok(long long time,int goal){
    int i;
    long long total=0;
    for(i=0;i<n;i++){
        total+=time/a[i];
        if(total>=goal){    //once we produce no less than goal, then it must be true
            return true;
        }
    }
    return false;
}
int main(){
    int t,i;
    scanf("%d%d",&n,&t);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    long long l=0, r=1e18, ans=-1;
    while(l<=r){
        long long mid=(l+r)/2;

        if(ok(mid, t)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}