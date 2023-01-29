#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long prefix[200010];
int main(){
    int n,q,i;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    //sort to use lowerbound
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }

    //find the # of elements that >=x, <x, and their sum respectively
    for(i=0;i<q;i++){
        int x;
        scanf("%d",&x);
        int idx = lower_bound(a+1,a+1+n,x)-a;
        long long sum_smaller_than_x = prefix[idx-1];
        long long sum_larger_than_x = prefix[n]-sum_smaller_than_x;
        int smaller_cnt = idx-1, larger_cnt = n-smaller_cnt;
        
        printf("%lld\n",sum_larger_than_x - sum_smaller_than_x - 1ll*(larger_cnt - smaller_cnt)*x);
    }
    return 0;
}