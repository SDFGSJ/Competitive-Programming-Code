#include<bits/stdc++.h>
using namespace std;
int a[200010];
int cnt[200010];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int i;
        int n,sum=0,nowmax;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }

        sort(cnt+1,cnt+1+n,greater<int>());
        
        nowmax=cnt[1];
        for(i=1;i<=n;i++){
            if(nowmax<=0){
                break;
            }
            sum+=min(cnt[i],nowmax);
            nowmax=min(nowmax-1,cnt[i]-1);
        }

        printf("%d\n",sum);
        for(i=1;i<=n;i++){
            cnt[i]=0;
        }
    }
    return 0;
}