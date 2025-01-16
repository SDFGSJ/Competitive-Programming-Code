#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int n;
bool valid(long long num, long long k){
    return num-(upper_bound(a,a+n,num)-a) >= k;
}
int main(){
    int q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    while(q--){
        long long k;
        scanf("%lld",&k);
        long long L=0,R=2e18;
        while(L+1<R){
            long long mid=L+(R-L)/2;
            if(valid(mid,k)){
                R=mid;
            }else{
                L=mid;
            }
        }
        printf("%lld\n",R);
    }
    return 0;
}
/*
bs
let integer i be the f(i)-th smallest
f(x) = # of elements in [1,x] - |{i|a[i]<=x}| = x - upper_bound(x)
find the first i s.t. f(i)>=k
notice that the upper bound R should be greater than 1e18
else you will get WA on cases like a[n]=1e18, k=1e18 if you set R=1e18
*/