#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    scanf("%d",&n);
    if(n<=2){
        printf("1\n1\n");
    }else if(n==3){
        printf("2\n1 3\n");
    }else if(n==4){
        printf("4\n3 1 4 2\n");
    }else{
        printf("%d\n",n);
        for(i=1;i<=n;i+=2){
            printf("%d ",i);
        }
        for(i=2;i<=n;i+=2){
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}