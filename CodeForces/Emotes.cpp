#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    int n,m,k,i;
    long long ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n,greater<long long>());

    //m/(k+1) rounds,m%(k+1) numbers left => pick a[0]
    ans=(m/(k+1))*(k*a[0]+a[1]) + (m%(k+1))*a[0];
    printf("%lld\n",ans);
    return 0;
}