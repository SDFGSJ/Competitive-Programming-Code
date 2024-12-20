#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=0;i<n;i++){
        int d,a;
        scanf("%d%d",&d,&a);
        if(d==1){
            if(1600<=r && r<=2799){
                r+=a;
            }
        }else{
            if(1200<=r && r<=2399){
                r+=a;
            }
        }
    }
    printf("%d\n",r);
    return 0;
}