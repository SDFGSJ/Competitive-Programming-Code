#include<bits/stdc++.h>
using namespace std;
int grid[1505][1505];
void print(){
    for(int i=0;i<=4;i++){
        for(int j=0;j<=4;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("===============\n");
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        grid[a][b]++,grid[c][d]++;
        grid[a][d]--,grid[c][b]--;
    }

    for(int i=0;i<=1500;i++){
        for(int j=1;j<=1500;j++){
            grid[i][j]+=grid[i][j-1];
        }
    }
    //print();

    for(int i=1;i<=1500;i++){
        for(int j=0;j<=1500;j++){
            grid[i][j]+=grid[i-1][j];
        }
    }
    //print();

    int cnt=0;
    for(int i=0;i<=1500;i++){
        for(int j=0;j<=1500;j++){
            if(grid[i][j]>0){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}