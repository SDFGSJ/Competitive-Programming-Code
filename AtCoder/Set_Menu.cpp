#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[200010],preb[200010];
int main(){
    int n,m;
    long long p;
    scanf("%d%d%lld",&n,&m,&p);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%lld",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);
    preb[0]=b[0];
    for(int i=1;i<m;i++){
        preb[i]=preb[i-1]+b[i];
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        int smaller=lower_bound(b,b+m,p-a[i])-b;  //#b[i]s s.t. a[i]+b[i]<p
        int larger=m-smaller;    //#b[i]s s.t. a[i]+b[i]>=p
        ans+=smaller*a[i]+preb[smaller-1]+larger*p;
    }
    printf("%lld\n",ans);
    return 0;
}