#include<bits/stdc++.h>
using namespace std;
int imos[1000010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        imos[a]++,imos[b+1]--;
    }

    int ans=imos[0];
    for(int i=1;i<=1000000;i++){
        imos[i]+=imos[i-1];
        ans=max(ans,imos[i]);
    }
    printf("%d\n",ans);
    return 0;
}
/*
imos
*/