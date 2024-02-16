#include<bits/stdc++.h>
using namespace std;
int a[100010];
int cnt[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=1){
            cnt[a[i]-1]++;
        }
        cnt[a[i]]++;
        cnt[a[i]+1]++;
    }
    int ans=-1;
    for(int i=0;i<100000;i++){
        ans=max(ans,cnt[i]);
    }
    printf("%d\n",ans);
    return 0;
}