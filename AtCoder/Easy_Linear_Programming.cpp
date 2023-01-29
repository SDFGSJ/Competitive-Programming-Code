#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,k,ans=0;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    
    ans+=min(a,k);
    k-=min(a,k);

    k-=min(b,k);

    ans-=min(c,k);
    k-=min(c,k);

    printf("%d",ans);
    return 0;
}