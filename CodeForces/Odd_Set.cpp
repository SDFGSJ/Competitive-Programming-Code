#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,num,odd=0,even=0;
        scanf("%d",&n);
        for(i=0;i<2*n;i++){
            scanf("%d",&num);
            if(num%2==0){
                even++;
            }else{
                odd++;
            }
        }
        if(odd==even){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}