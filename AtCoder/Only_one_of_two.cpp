#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
bool check(long long mid){
    return mid/n + mid/m - mid/lcm(n,m)*2 >= k;
}
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    long long l=0,r=1e18;
    while(l+1<r){
        long long mid=l+(r-l)/2;
        if(check(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%lld\n",r);
    return 0;
}