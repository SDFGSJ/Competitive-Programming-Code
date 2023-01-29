#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n;
        long long k,ans=0ll,sum=0ll;
        scanf("%d%lld",&n,&k);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        sum=a[0];
        for(i=0;i+1<n;i++){
            long long x=(long long)ceil(100.0*a[i+1]/k);
            if(sum<x){
                ans+=x-sum;
                sum+=x-sum;
            }
            sum+=a[i+1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
a[i+1] / sum_i ? k/100
let x = minimum number such that a[i+1]/x <= k/100
suppose a[i+1]/x <= k/100
100*a[i+1] <= k*x
100*a[i+1]/k <= x
so x = ceiling(100*a[i+1]/k)
if sum_i<x then ans,sum_i need to +(x-sum_i)
*/