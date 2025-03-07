#include<bits/stdc++.h>
using namespace std;
char grid[55][55];
void fillgrid(int i,int j,char ch){
    for(int r=i;r<=j;r++){
        for(int c=i;c<=j;c++){
            grid[r][c]=ch;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        int j=n+1-i;
        if(i<=j){
            if(i%2){
                fillgrid(i,j,'#');
            }else{
                fillgrid(i,j,'.');
            }
        }
    }

    for(int i=1;i<=n;i++){
        printf("%s\n",grid[i]+1);
    }
    return 0;
}