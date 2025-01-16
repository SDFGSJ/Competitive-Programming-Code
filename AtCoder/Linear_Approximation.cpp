#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]-=i;
    }

    sort(a+1,a+1+n);
    int b=a[(1+n)/2];
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i]-b);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
|Ai-(b+i)| = |Ai-b-i| = |(Ai-i)-b| = |Bi-b|
so let B[i] = A[i]-i
the problem remains to find a num b that minimize sum(|Bi-b|)
sort B[] and pick the median
*/