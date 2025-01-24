#include<bits/stdc++.h>
using namespace std;
char s[100010];
int pre[100010];
int main(){
    int n,q;
    scanf("%d%d%s",&n,&q,s+1);

    for(int i=1;i<=n;i++){
        pre[i]+=pre[i-1];
        if(s[i-1]=='A' && s[i]=='C'){
            pre[i]++;
        }
    }

    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=pre[r]-pre[l-1];
        if(s[l]=='C' && s[l-1]=='A'){
            ans--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
prefix sum
ans=pre[r]-pre[l-1]
if s[l-1],s[l]=="AC", then decrement ans by 1
*/