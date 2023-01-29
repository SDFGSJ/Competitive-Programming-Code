#include<bits/stdc++.h>
using namespace std;
long long a[100010];    //prevent a[i]*a[j] overflow
int main(){
    long long t,i,j;
    scanf("%lld",&t);
    while(t--){
        long long n,cnt=0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }

        /*
        i+j==a[i]*[j]>=a[j]
        j=a[i]-i and adjust it until j>i
        everytime add a[i] because rhs is a multiple of a[i]
        */
        for(i=1;i<n;i++){
            j=a[i]-i;
            while(j<=i){
                j+=a[i];
            }
            for( ;j<=n; j+=a[i]){
                if(i+j==a[i]*a[j]){
                    cnt++;
                }
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}