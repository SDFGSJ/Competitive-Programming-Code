#include<bits/stdc++.h>
using namespace std;
int a[100010],pre[100010],suf[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++){
        pre[i]=max(pre[i-1], a[i]);
    }
    for(int i=n;i>=0;i--){
        suf[i]=max(suf[i+1], a[i]);
    }

    int d;
    scanf("%d",&d);
    while(d--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",max(pre[l-1], suf[r+1]));
    }
    return 0;
}