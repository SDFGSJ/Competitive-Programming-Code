#include<bits/stdc++.h>
using namespace std;
int t[105],l[105];
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++){
        scanf("%d%d",&t[i],&l[i]);
    }
    for(int i=1;i<=d;i++){
        int ans=0;
        for(int j=0;j<n;j++){
            ans=max(ans,t[j]*(l[j]+i));
        }
        printf("%d\n",ans);
    }
    return 0;
}