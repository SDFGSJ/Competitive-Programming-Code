#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,x,ans=0ll;
    scanf("%lld%lld%lld",&a,&b,&x);
    ans=b/x-a/x;
    if(a%x==0){
        ans++;
    }
    printf("%lld",ans);
    return 0;
}