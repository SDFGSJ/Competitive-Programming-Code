#include<bits/stdc++.h>
using namespace std;
long long apre[200010],bpre[200010];
int main(){
    int n,m;
    long long k;
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&apre[i]);
        apre[i]+=apre[i-1];
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&bpre[i]);
        bpre[i]+=bpre[i-1];
    }

    int ans=0;
    for(int i=0;i<=n;i++){  //enumerate a[i], *can choose not to take books from a
        if(k<apre[i]){
            break;
        }

        //find 1st bpre[j] s.t. apre[i]+bpre[j]>k, -1 so that apre[i]+bpre[j]<=k
        //*can also choose not to take books from b
        int idx=upper_bound(bpre,bpre+1+m, k-apre[i])-1-bpre;
        ans=max(ans,i+idx);
    }
    printf("%d\n",ans);
    return 0;
}
/*
me: prefix sum + binary search => O(NlogM)
editorial: 2 pointers crawling => O(N+M)
*/