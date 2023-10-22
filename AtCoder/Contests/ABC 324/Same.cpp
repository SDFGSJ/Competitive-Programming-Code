#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0,num;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        sum+=num;
    }
    if(sum!=n*num){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}