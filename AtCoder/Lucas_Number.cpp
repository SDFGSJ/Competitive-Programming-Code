#include<bits/stdc++.h>
using namespace std;
long long ans[100];
int main(){
    int n;
    scanf("%d",&n);
    ans[0]=2,ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    printf("%lld\n",ans[n]);
    return 0;
}