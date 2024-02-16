#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool check(int n,long long num){
    for(int i=0;i<n;i++){
        num+=a[i];
        if(num<0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }

    long long L=-1,R=200000000000000;
    while(L+1<R){
        long long mid=L+(R-L)/2;
        if(check(n,mid)){
            R=mid;
        }else{
            L=mid;
        }
    }
    for(int i=0;i<n;i++){
        R+=a[i];
    }
    printf("%lld\n",R);
    return 0;
}