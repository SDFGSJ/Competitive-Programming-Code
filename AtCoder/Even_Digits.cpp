#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    scanf("%lld",&n);
    n--;
    long long ans=0,base=1;
    while(n>0){
        ans+=2*(n%5)*base;
        base*=10;
        n/=5;
    }
    printf("%lld\n",ans);
    return 0;
}