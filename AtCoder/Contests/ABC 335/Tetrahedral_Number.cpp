#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=n-i-j;k++){
                printf("%d %d %d\n",i,j,k);
            }
        }
    }
    return 0;
}