#include<bits/stdc++.h>
using namespace std;
int t[105],v[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&t[i],&v[i]);
    }

    int ans=0;
    for(int time=1,idx=0;time<=100 && idx<n;time++){
        if(ans>0){
            ans--;
        }

        if(time==t[idx]){
            ans+=v[idx];
            idx++;
        }
    }
    printf("%d\n",ans);
    return 0;
}