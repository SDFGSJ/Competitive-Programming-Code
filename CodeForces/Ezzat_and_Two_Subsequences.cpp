#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n;
        long long sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i];
        }

        sort(a,a+n,greater<int>());
        
        double ans=a[0] + (sum-a[0])*1.0 / (n-1);
        printf("%.9f\n",ans);
    }
    return 0;
}