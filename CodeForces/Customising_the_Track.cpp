#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        long long n,num;
        long long sum=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&num);
            sum+=num;
        }
        /*if(sum<n){
            printf("%lld\n",sum*(n-sum));
        }else{
            if(sum%n==0){
                printf("0\n");
            }else{
                long long cnt=sum%n;
                printf("%lld\n",cnt*(n-cnt));
            }
        }*/
        long long cnt=sum%n;
        long long ans=cnt*(n-cnt);
        printf("%lld\n",ans);
    }
    return 0;
}