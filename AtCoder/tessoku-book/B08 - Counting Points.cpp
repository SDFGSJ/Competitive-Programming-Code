#include<bits/stdc++.h>
using namespace std;
int grid[1505][1505];
int pre[1505][1505];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        grid[x][y]++;
    }

    for(int i=1;i<=1500;i++){
        for(int j=1;j<=1500;j++){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+grid[i][j];
        }
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",pre[c][d]-pre[c][b-1]-pre[a-1][d]+pre[a-1][b-1]);
    }
    return 0;
}