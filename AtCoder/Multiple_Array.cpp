#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        if((ans+a[i]) % b[i] != 0){
            ans += b[i] - ((ans+a[i]) % b[i]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}