#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long d[200010];  //have n-1 numbers
int main(){
    int n,i,idx=0;
    long long k,diff;
    
    scanf("%d%lld%lld",&n,&k,&diff);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);

    for(i=0;i<n-1;i++){
        d[i]=abs(a[i+1]-a[i]);
    }
    sort(d,d+n-1,greater<long long>());

    /*printf("d[]=\n");
    for(i=0;i<n-1;i++){
        printf("%lld,",d[i]);
    }
    printf("\n");*/

    idx=0;
    while(d[idx]>diff){
        idx++;
    }
    for(i=idx-1;i>=0 && k>0;i--){
        if(d[i]%diff==0){
            if(d[i]/diff-1 > k){
                break;
            }else{
                k-=(d[i]/diff-1);
            }
        }else{
            if(d[i]/diff > k){
                break;
            }else{
                k-=(d[i]/diff);
            }
        }
    }
    printf("%d\n",i+2);
    return 0;
}