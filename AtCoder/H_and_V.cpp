#include<bits/stdc++.h>
using namespace std;
char grid[10][10];
int h,w,k;
bool paint(int rowmask,int colmask){
    int res=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]=='#' && (((rowmask>>i) & 1) == 0) && (((colmask>>j) & 1) == 0)){
                res++;
            }
        }
    }
    return res==k;
}
int main(){
    scanf("%d%d%d",&h,&w,&k);
    for(int i=0;i<h;i++){
        scanf("%s",grid[i]);
    }

    int ans=0;
    for(int rowbit=0;rowbit<(1<<h);rowbit++){
        for(int colbit=0;colbit<(1<<w);colbit++){
            ans+=paint(rowbit,colbit);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
bit enumeration
bitmask's i-th bit is 0 = row/col i is not painted in red
a black grid is valid <=> that grid is not on the row/col painted in red
*/