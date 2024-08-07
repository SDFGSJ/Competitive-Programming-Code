#include<bits/stdc++.h>
using namespace std;
long long a[100010],pre[100010];
bool valid(int l,int r, int k){
    return pre[r]-pre[l-1]>k;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        int L=0,R=n+1;
        while(L+1<R){
            int mid=L+(R-L)/2;
            if(valid(i,mid,k)){
                R=mid;
            }else{
                L=mid;
            }
        }
        ans+=R-i;
    }
    printf("%lld\n",ans);
    return 0;
}