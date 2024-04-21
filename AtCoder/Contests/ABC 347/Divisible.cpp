#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num%k==0){
            printf("%d ",num/k);
        }
    }
    printf("\n");
    return 0;
}