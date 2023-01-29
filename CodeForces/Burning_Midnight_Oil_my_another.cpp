#include<bits/stdc++.h>
using namespace std;
int calc(int);
int n,k;
int main(){
    int l,r,mid=1,sum=0;
    scanf("%d%d",&n,&k);
 
    l=1,r=n;
    while(l<r){
        mid=(l+r)/2;
 
        sum=calc(mid);
 
        if(sum>=n){
            r=mid;
        }else if(sum<n){
            l=mid+1;
        }
    }
    printf("%d\n",l);   //we want the smallest number
    return 0;
}
int calc(int num){
    int s=0;
    long long div=1ll;
    while(num/div!=0){
        s+=num/div;
        div*=k;
    }
    return s;
}
