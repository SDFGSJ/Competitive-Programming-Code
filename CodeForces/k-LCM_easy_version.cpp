#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        if(n%2==1){
            printf("1 %d %d\n",(n-1)/2,(n-1)/2);
        }else if(n%4==0){
            printf("%d %d %d\n",n/2,n/4,n/4);
        }else{
            printf("2 %d %d\n",(n-2)/2,(n-2)/2);
        }
    }
    return 0;
}