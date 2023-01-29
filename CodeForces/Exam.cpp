#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    int n,i;
    scanf("%d",&n);
    if(n==1 || n==2){
        printf("1\n1\n");
    }else if(n==3){
        printf("2\n1 3\n");
    }else if(n==4){
        printf("4\n3 1 4 2\n");
    }else{
        int num=1;
        printf("%d\n",n);
        for(i=1;i<=n;i++){
            if(i%2==1){
                a[i]=num;
                num++;
            }else{
                a[i]=a[i-1] + (n+1)/2;  //doesnt matter n is even or odd
            }
        }
        for(i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}