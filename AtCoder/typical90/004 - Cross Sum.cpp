#include<bits/stdc++.h>
using namespace std;
int a[2005][2005];
int rowsum[2005],colsum[2005];
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&a[i][j]);
            rowsum[i]+=a[i][j];
            colsum[j]+=a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            printf("%d ",rowsum[i]+colsum[j]-a[i][j]);
        }
        printf("\n");
    }
    return 0;
}