#include<bits/stdc++.h>
using namespace std;
char a[55][55],b[55][55];
int n,m;
bool match(int r,int c){
    for(int i=r;i<=r+m-1;i++){
        for(int j=c;j<=c+m-1;j++){
            if(a[i][j]!=b[i-r+1][j-c+1]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=m;i++){
        scanf("%s",b[i]+1);
    }

    for(int i=1;i+m-1<=n;i++){
        for(int j=1;j+m-1<=n;j++){
            if(match(i,j)){
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
/*
brute force
*/