#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        bool good=false;
        int n,k,num;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++){
            scanf("%d",&num);
            if(num==k){
                good=true;
            }
        }
        if(good){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}