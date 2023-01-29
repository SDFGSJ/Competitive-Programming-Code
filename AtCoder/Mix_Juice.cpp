#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n,k,ans=0,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    sort(a,a+n);
    for(i=0;i<k;i++){
        ans+=a[i];
    }
    
    printf("%d",ans);
    return 0;
}