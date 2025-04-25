#include<bits/stdc++.h>
using namespace std;
int a[105][105][105],pre[105][105][105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                scanf("%d",&a[i][j][k]);
            }
        }
    }

    for(int z=1;z<=n;z++){
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                pre[x][y][z]=pre[x-1][y][z]+pre[x][y-1][z]-pre[x-1][y-1][z]+a[x][y][z];
            }
        }
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int lx,rx,ly,ry,lz,rz;
        scanf("%d%d%d%d%d%d",&lx,&rx,&ly,&ry,&lz,&rz);
        int ans=0;
        for(int z=lz;z<=rz;z++){
            ans+=pre[rx][ry][z]-pre[lx-1][ry][z]-pre[rx][ly-1][z]+pre[lx-1][ly-1][z];
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2D prefix sum
sum along z axis
*/