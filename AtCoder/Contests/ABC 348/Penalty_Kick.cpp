#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%3!=0){
            printf("o");
        }else{
            printf("x");
        }
    }
    printf("\n");
    return 0;
}