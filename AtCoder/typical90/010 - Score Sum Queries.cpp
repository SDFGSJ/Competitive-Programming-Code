#include<bits/stdc++.h>
using namespace std;
int prefix[3][100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int c,p;
        scanf("%d%d",&c,&p);
        prefix[c][i]=prefix[c][i-1]+p;
        prefix[3-c][i]=prefix[3-c][i-1];
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d %d\n",prefix[1][r]-prefix[1][l-1], prefix[2][r]-prefix[2][l-1]);
    }
    return 0;
}