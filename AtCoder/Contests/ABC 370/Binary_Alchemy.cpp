#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }

    int now=a[1][1];
    for(int i=2;i<=n;i++){
        if(now>=i){
            now=a[now][i];
        }else{
            now=a[i][now];
        }
    }
    printf("%d\n",now);
    return 0;
}