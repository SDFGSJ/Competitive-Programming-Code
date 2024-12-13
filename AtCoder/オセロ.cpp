#include<bits/stdc++.h>
using namespace std;
int imos[200010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        imos[l]++,imos[r+1]--;
    }

    for(int i=1;i<=n;i++){
        imos[i]+=imos[i-1];
        if(imos[i]%2){
            printf("1");
        }else{
            printf("0");
        }
    }
    printf("\n");
    return 0;
}
//imos