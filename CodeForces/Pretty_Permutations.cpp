#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n%2==0){
            for(i=1;i<=n/2;i++){
                printf("%d %d ",2*i,2*i-1);
            }
        }else{
            for(i=1;i<=(n-3)/2;i++){
                printf("%d %d ",2*i,2*i-1);
            }
            printf("%d %d %d ",n-1,n,n-2);
        }
        printf("\n");
    }
    return 0;
}