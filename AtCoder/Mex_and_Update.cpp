#include<bits/stdc++.h>
using namespace std;
int a[200010],cnt[200010];
set<int> mex;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=n){
            cnt[a[i]]++;
        }
    }

    for(int i=0;i<=n;i++){
        if(!cnt[i]){
            mex.emplace(i);
        }
    }

    for(int i=0;i<q;i++){
        int idx,x;
        scanf("%d%d",&idx,&x);

        if(a[idx]<=n){
            cnt[a[idx]]--;
            if(!cnt[a[idx]]){
                mex.emplace(a[idx]);
            }
        }
        a[idx]=x;
        if(a[idx]<=n){
            cnt[a[idx]]++;
            if(cnt[a[idx]]==1){
                mex.erase(a[idx]);
            }
        }

        printf("%d\n",*mex.begin());
    }
    return 0;
}
/*
cnt[i] = # of i in a[]
mex = set of int which are not in a[]
the mex of a length-N seq could only be [0,N], so if x>N, just ignore it
*/