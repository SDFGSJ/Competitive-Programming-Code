#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,l,r,ans=0ll;
    int m;
    scanf("%lld%d%lld%lld",&a,&m,&l,&r);
    if(l<=a && a<=r){
        ans=abs(l-a)/m + abs(r-a)/m + 1;
    }else if(a<l){
        ans=abs(r-a)/m - abs(l-a)/m + (abs(l-a)%m==0);
    }else{
        ans=abs(l-a)/m - abs(r-a)/m + (abs(r-a)%m==0);
    }
    printf("%lld\n",ans);
    return 0;
}