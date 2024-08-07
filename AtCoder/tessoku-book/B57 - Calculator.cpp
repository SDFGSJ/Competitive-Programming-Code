#include<bits/stdc++.h>
using namespace std;
int a[300010];
int digit_sum(int num){
    int result=0;
    while(num){
        result+=num%10;
        num/=10;
    }
    return result;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=n;i>=0;i--){
        a[i]=i-digit_sum(i);
    }

    for(int i=1;i<=n;i++){
        int num=i;
        for(int cnt=0;cnt<k && num>0;cnt++){
            num=a[num];
        }
        printf("%d\n",num);
    }
    return 0;
}