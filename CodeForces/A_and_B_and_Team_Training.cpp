#include<bits/stdc++.h>
using namespace std;
int main(){
    int exp,nb,ans=0;
    scanf("%d%d",&exp,&nb);

    while((exp>=1 && nb>=2) || (exp>=2 && nb>=1)){
        ans++;
        if(exp>=nb){
            exp-=2;
            nb-=1;
        }else{
            exp-=1;
            nb-=2;
        }
    }
    printf("%d\n",ans);
    return 0;
}