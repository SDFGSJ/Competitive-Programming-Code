#include<bits/stdc++.h>
using namespace std;
int a[300010],b[300010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long suma=0ll,sumb=0ll;
        int n,i;
        int mina=INT_MAX,minb=INT_MAX;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            mina=min(mina,a[i]);
            suma+=a[i];
        }
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
            minb=min(minb,b[i]);
            sumb+=b[i];
        }
        /*
        straight line 1: (min num of b[]) & a[]
        straight line 2: (min num of a[]) & b[]
        min(line 1, line 2)
        */
        printf("%lld\n",min(suma + (long long)minb*n, sumb + (long long)mina*n));
    }
    return 0;
}