#include<bits/stdc++.h>
using namespace std;
int a[25];
int main(){
    int n;
    scanf("%d",&n);
    int total=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        total+=a[i];
    }

    int ans=INT_MAX;
    for(int bit=0;bit<(1<<n);bit++){
        int group=0;
        for(int j=0;j<n;j++){
            if(bit&(1<<j)){
                group+=a[j];
            }
        }
        ans=min(ans,max(group, total-group));
    }
    printf("%d\n",ans);
    return 0;
}