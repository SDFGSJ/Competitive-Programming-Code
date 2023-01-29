#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a,b;
        bool yes=false;
        scanf("%d%d%d",&n,&a,&b);
        if(a==1){
            if( (n-1)%b==0 ){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }else if(b==1 || (n-1)%b==0){   //cant write n%a==0 since (n/a) may not be a power of a
            printf("YES\n");
        }else{
            long long num=1;
            while(num<=n){
                num*=a;
                if((n-num)%b==0 && n-num>=0){
                    printf("YES\n");
                    yes=true;
                    break;
                }
                
            }
            if(!yes){
                printf("NO\n");
            }
        }
    }
    return 0;
}