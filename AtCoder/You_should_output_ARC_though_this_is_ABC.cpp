#include<bits/stdc++.h>
using namespace std;
int a[2][2];
int main(){
    int r,c,i,j;
    scanf("%d%d",&r,&c);
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("%d\n",a[r-1][c-1]);
    return 0;
}