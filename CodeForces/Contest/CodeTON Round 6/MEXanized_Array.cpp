#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,x,sum;
    scanf("%d",&t);
    while(t--){
        sum=0;
        scanf("%d%d%d",&n,&k,&x);
        if(n<k || k>x+1){   //impossible
            printf("-1\n");
            continue;
        }else{
            sum=k*(k-1)/2;  //0+1+...+(k-1)
            if(k==x){
                sum+=(n-k)*(k-1);
            }else{
                sum+=(n-k)*x;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}