#include<bits/stdc++.h>
using namespace std;
int a[300010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++){
        int cnt=upper_bound(a,a+n,a[i]+m-1)-lower_bound(a,a+n,a[i]);
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}