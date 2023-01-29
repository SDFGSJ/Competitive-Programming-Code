#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k1,k2,w,b;
        scanf("%d%d%d%d%d",&n,&k1,&k2,&w,&b);
        /*if(w==0 && b==0){
            printf("yes\n");
            continue;
        }*/
        if(k1+k2<2*w || 2*n-k1-k2<2*b){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
    return 0;
}