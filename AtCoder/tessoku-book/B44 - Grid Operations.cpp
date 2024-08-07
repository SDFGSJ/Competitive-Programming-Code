#include<bits/stdc++.h>
using namespace std;
int grid[505][505],pos[505];    //the content of row i of the original grid is now at pos[i]
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&grid[i][j]);
        }
        pos[i]=i;
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        x--,y--;
        if(op==1){
            swap(pos[x],pos[y]);
        }else{
            printf("%d\n",grid[pos[x]][y]);
        }
    }
    return 0;
}