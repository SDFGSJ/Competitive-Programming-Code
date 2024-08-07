#include<bits/stdc++.h>
using namespace std;
int a[100010],prefix[100010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",prefix[r]-prefix[l-1]);
    }
    return 0;
}