#include<bits/stdc++.h>
using namespace std;
char grid[3005][3005],ans[3005][3005];
int n;
void putch(int x,int y,int mod){
    if(mod==0){
        ans[x][y]=grid[x][y];
    }else if(mod==1){
        ans[y][n+1-x]=grid[x][y];
    }else if(mod==2){
        ans[n+1-x][n+1-y]=grid[x][y];
    }else{
        ans[n+1-y][x]=grid[x][y];
    }
}
void trans(int num){
    for(int col=num;col<=n+1-num;col++){
        putch(num,col,num%4);
        putch(n+1-num,col,num%4);
    }
    for(int row=num;row<=n+1-num;row++){
        putch(row,num,num%4);
        putch(row,n+1-num,num%4);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",grid[i]+1);
    }

    for(int i=1;i<=n/2;i++){
        trans(i);
    }

    for(int i=1;i<=n;i++){
        printf("%s\n",ans[i]+1);
    }
    return 0;
}