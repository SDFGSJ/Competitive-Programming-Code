#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i*i<n;i++){

    }
    if(i*i>n){
        i--;
    }
    printf("%d\n",i*i);
    return 0;
}