#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,ans=0;
    scanf("%d%d",&x,&y);
    if(x<y){
        ans=(y-x)/10;
        if((y-x)%10!=0){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}