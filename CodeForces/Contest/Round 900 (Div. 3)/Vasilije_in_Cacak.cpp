#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n,k,x,l,r;    // lower, upper bound
        scanf("%lld%lld%lld",&n,&k,&x);
        l=k*(k+1)/2;
        r=k*(n + n-k+1)/2;
        if(l<= x && x<=r){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}