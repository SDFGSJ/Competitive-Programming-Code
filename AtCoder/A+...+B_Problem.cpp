#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    long long ans;
    scanf("%d%d%d",&n,&a,&b);
    if(n==1){
        if(a==b){
            ans=1;
        }else{
            ans=0;
        }
    }else{
        if(a>b){
            ans=0;
        }else{
            ans=1ll*(n-2)*(b-a)+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}