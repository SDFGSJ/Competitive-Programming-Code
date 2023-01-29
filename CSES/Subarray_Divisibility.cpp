#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long prefix[200010];
int mod[200010];    //mod[i] = # of prefix sum that %n==i
int main(){
    /*math idea:
    if a%n == b%n == m, then (a-b)%n==0
    so find the total number of prefix sum that has the same remainder
    then we pick any 2 nums from n, that is C(n,2)
    */
    int n,i;
    long long cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
 
    //calculate prefix sum
    for(i=0;i<n;i++){
        if(i==0){
            prefix[i]=a[i];
        }else{
            prefix[i]=prefix[i-1]+a[i];
        }

        if(prefix[i]%n < 0){    //beware of <0 since idx never < 0, or else get RE
            mod[prefix[i]%n + n]++;
        }else{
            mod[prefix[i]%n]++;
        }
    }

    for(i=0;i<n;i++){
        cnt += (1ll*mod[i]*(mod[i]-1))/2;   //C(n,2)
        if(prefix[i]%n==0){ //check if prefix sum itself is divisible by n
            cnt++;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}