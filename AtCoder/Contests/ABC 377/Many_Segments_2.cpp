#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[200010];
int sufmin[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);

    sufmin[n-1]=a[n-1].second;
    for(int i=n-1;i>=0;i--){
        sufmin[i-1]=min(sufmin[i],a[i-1].second);
    }
    /*for(int i=0;i<n;i++){
        printf("%d\n",sufmin[i]);
    }*/
    long long ans=0;
    for(int i=1;i<=m;i++){
        int idx=lower_bound(a,a+n,make_pair(i,0))-a;
        //printf("idx=%d\n",idx);
        if(idx==n){
            //printf("+%d-%d+1\n",m,i);
            ans+=m-i+1;
        }else{
            //printf("+%d-%d\n",sufmin[idx],i);
            ans+=sufmin[idx]-i;
        }
    }
    printf("%lld\n",ans);
    return 0;
}