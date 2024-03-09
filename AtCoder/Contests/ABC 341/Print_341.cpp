#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<2*n+1;i++){
        if(i%2==0){
            printf("1");
        }else{
            printf("0");
        }
    }
    printf("\n");
    return 0;
}