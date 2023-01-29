#include<bits/stdc++.h>
using namespace std;
int calc(int);
int n,k;
int main(){
    int l,r,mid=1,sum=0,ans=-1;
    scanf("%d%d",&n,&k);

    l=1,r=n;
    while(l<r){
        mid=(l+r)/2;

        sum=calc(mid);

        if(sum>n){
            r=mid;
        }else if(sum<n){
            l=mid+1;
        }else{
            ans=mid;
            break;
        }
    }

    int lsum=calc(l);
    int rsum=calc(r);
    if(ans==-1){    //means no answer right now
        if(sum<n){  //if the result from mid is too small
            ans=l;
        }else{
            if(lsum>=n && lsum<sum){
                ans=l;
            }else{
                ans=mid;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
int calc(int num){
    int s=0;
    long long div=1ll;  //beware of overflow
    while(num/div!=0){
        s+=num/div;
        div*=k;
    }
    return s;
}