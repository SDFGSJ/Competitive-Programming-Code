#include<bits/stdc++.h>
using namespace std;
int grid[1505][1505],prefix[1505][1505];
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf("%d",&grid[i][j]);
        }
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+grid[i][j];
        }
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",prefix[c][d]-prefix[c][b-1]-prefix[a-1][d]+prefix[a-1][b-1]);
    }
    return 0;
}