#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n;
        long long ans=0ll;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        for(i=0;i+1<n;i++){
            if(a[i]*a[i+1]>ans){
                ans=a[i]*a[i+1];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//the answer is max(the products of adjacent elements in a)