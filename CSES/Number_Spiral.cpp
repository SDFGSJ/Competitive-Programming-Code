#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int r,c;
        scanf("%d%d",&r,&c);

        //pure observation
        if(r<c){
            if(c%2){    //odd
                printf("%lld\n",1ll*c*c - r + 1);
            }else{  //even
                printf("%lld\n",1ll*(c-1)*(c-1) + r);
            }
        }else if(r>c){
            if(r%2){    //odd
                printf("%lld\n",1ll*(r-1)*(r-1) + c);
            }else{  //even
                printf("%lld\n",1ll*r*r - c + 1);
            }
        }else{
            printf("%lld\n",1ll*r*(r-1)+1);
        }
    }
    return 0;
}