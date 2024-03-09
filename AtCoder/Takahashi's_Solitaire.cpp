#include<bits/stdc++.h>
using namespace std;
long long a[400010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    long long total=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        total+=a[i];
    }

    sort(a,a+n);    //sort the first n element
    for(int i=n;i<2*n;i++){
        a[i]=a[i-n];    //append a[0]~a[n-1] to the back of a
    }

    long long maxsum=-1, sum=0;
    for(int i=0;i+1<2*n;i++){
        sum+=a[i];
        if(abs(a[i+1]-a[i])>1 && (a[i]+1)%m!=a[i+1]){
            maxsum=max(maxsum,sum);
            sum=0;
        }
    }
    if(maxsum==-1){ //special case n=1
        printf("0\n");
    }else{
        printf("%lld\n",total-maxsum);
    }
    return 0;
}