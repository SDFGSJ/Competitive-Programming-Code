#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
int main(){
    long long d,ans=LONG_LONG_MAX;
    scanf("%lld",&d);
    for(long long i=0;i*i<=d;i++){
        v.emplace_back(i*i);
    }
    int n=v.size(),l=0,r=n-1;
    while(l<=r){
        long long now=v[l]+v[r];
        ans=min(ans,abs(d-now));
        if(now>d){
            r--;
        }else{
            l++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}