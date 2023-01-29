#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        //n days,k shows,d consecutive days
        int n,k,d,ans=1000;
        scanf("%d%d%d",&n,&k,&d);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i+d<=n;i++){
            set<int> s;
            for(j=0;j<d;j++){
                s.insert(a[i+j]);
            }
            ans=min(ans,(int)s.size());
        }
        printf("%d\n",ans);
    }
    return 0;
}