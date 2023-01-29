#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int xa,ya,xb,yb,xf,yf;
        scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xf,&yf);
        if(ya==yf && yf==yb && min(xa,xb)<xf && xf<max(xa,xb)){
            printf("%d\n",abs(xa-xb)+2);
        }else if(xa==xf && xf==xb && min(ya,yb)<yf && yf<max(ya,yb)){
            printf("%d\n",abs(ya-yb)+2);
        }else{
            printf("%d\n",abs(xa-xb)+abs(ya-yb));
        }
    }
    return 0;
}