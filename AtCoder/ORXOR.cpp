#include<bits/stdc++.h>
using namespace std;
int a[25];
int calc(int n,int mask){
    int or_sum=0,xor_sum=0;
    for(int i=0;i<n;i++){
        or_sum|=a[i];
        if(mask&(1<<i)){
            xor_sum^=or_sum;
            or_sum=0;
        }
    }
    if(or_sum!=0){
        xor_sum^=or_sum;
    }
    return xor_sum;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int ans=2e9;
    for(int mask=0;mask<(1<<(n-1));mask++){
        ans=min(ans,calc(n,mask));
    }
    printf("%d\n",ans);
    return 0;
}
/*
1 | 3 | 5 | 7 => n nums, n-1 bars
enumerate all |'s using bitmask
*/