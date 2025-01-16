#include<bits/stdc++.h>
using namespace std;
int imos[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        imos[l]++,imos[r+1]--;
    }

    int ans=0;
    for(int i=1;i<=100000;i++){
        imos[i]+=imos[i-1];
        if(imos[i]==m){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
imos
*/