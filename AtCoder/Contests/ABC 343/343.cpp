#include<bits/stdc++.h>
using namespace std;
bool ispalin(long long n){
    vector<int> v;
    while(n!=0){
        v.emplace_back(n%10);
        n/=10;
    }
    /*for(auto num:v){
        printf("%d ",num);
    }
    printf("\n");*/
    for(int i=0;i<v.size();i++){
        if(v[i]!=v[v.size()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    long long n,ans=0;
    scanf("%lld",&n);
    for(long long i=0;i*i*i<=n;i++){
        if(ispalin(i*i*i)){
            ans=i*i*i;
        }
    }
    printf("%lld\n",ans);
    return 0;
}