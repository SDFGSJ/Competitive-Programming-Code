#include<bits/stdc++.h>
using namespace std;
int a[200010],sorta[200010];
long long prefix[200010];
int main(){
    int n;
    scanf("%d",&n);
    long long sum=0ll;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sorta[i]=a[i];
        sum+=a[i];
    }
    sort(sorta,sorta+n);

    prefix[0]=sorta[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+sorta[i];
    }

    for(int i=0;i<n;i++){
        int idx=upper_bound(sorta,sorta+n,a[i])-sorta;
        printf("%lld ",sum-prefix[idx-1]);
    }
    return 0;
}