#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(l<=num && num<=r){
            printf("%d ",num);
        }else if(abs(num-l)<abs(num-r)){
            printf("%d ",l);
        }else{
            printf("%d ",r);
        }
    }
    return 0;
}