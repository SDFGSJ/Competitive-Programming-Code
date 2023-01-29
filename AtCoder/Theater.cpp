#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l,r,ans=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&l,&r);
        ans+=r-l+1;
    }
    printf("%d\n",ans);
    return 0;
}