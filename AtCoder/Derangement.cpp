#include<bits/stdc++.h>
using namespace std;
int p[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }

    int ans=0;
    for(int i=1;i+1<=n;i++){
        if(p[i]==i){
            ans++;
            swap(p[i],p[i+1]);
        }
    }
    if(p[n]==n){
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
/*
scan from the start, if p[i]==i then swap p[i] with p[i+1]
beware of p[n]==n
*/