#include<bits/stdc++.h>
using namespace std;
int a[35][35];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==0 || i==j){
                a[i][j]=1;
            }else{
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}