#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int min_step=2*n-2;
    if(k>=min_step && (k-min_step)%2==0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}