#include<bits/stdc++.h>
using namespace std;
set<long long> ans;
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            ans.emplace(i);
            ans.emplace(n/i);
        }
    }
    for(auto num:ans){
        printf("%lld\n",num);
    }
    return 0;
}