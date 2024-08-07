#include<bits/stdc++.h>
using namespace std;
vector<long long> factor;
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            factor.emplace_back(i);
            n/=i;
        }
    }
    if(n!=1){
        factor.emplace_back(n);
    }

    int ans=0;
    for(int i=0;i<31;i++){
        if((1<<i) >= factor.size()){
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}