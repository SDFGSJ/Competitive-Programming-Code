#include<bits/stdc++.h>
using namespace std;
map<long long,int> m;    //<num,exp> => num**exp
int main(){
    long long n,p,ans=1;
    scanf("%lld%lld",&n,&p);
    for(long long i=2;i*i<=p;i++){
        while(p%i==0){
            m[i]++;
            p/=i;
        }
    }
    if(p!=1){
        m[p]++;
    }
    for(auto [num,exp]:m){
        if(exp>=n){
            ans*=(long long)pow(num, exp/n);
        }
    }
    printf("%lld\n",ans);
    return 0;
}