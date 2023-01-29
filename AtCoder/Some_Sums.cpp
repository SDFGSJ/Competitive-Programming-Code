#include<bits/stdc++.h>
using namespace std;
int digit(int num){
    int result=0;
    while(num>0){
        result+=(num%10);
        num/=10;
    }
    return result;
}
int main(){
    int n,a,b,ans=0,i;
    scanf("%d%d%d",&n,&a,&b);
    for(i=1;i<=n;i++){
        int sum=digit(i);
        if(a<=sum && sum<=b){
            ans+=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}