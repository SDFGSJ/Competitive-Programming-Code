#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    long long ans=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(i%3!=0 && i%5!=0){
            ans+=i;
        }
    }
    printf("%lld",ans);
    return 0;
}