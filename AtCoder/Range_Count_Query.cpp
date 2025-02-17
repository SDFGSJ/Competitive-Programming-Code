#include<bits/stdc++.h>
using namespace std;
vector<int> idx[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        idx[num].emplace_back(i);
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        int cnt=upper_bound(idx[x].begin(),idx[x].end(),r)-lower_bound(idx[x].begin(),idx[x].end(),l);
        printf("%d\n",cnt);
    }
    return 0;
}
/*
idx[num] = list of idx where num appears at in the array
# of target in [l,r] = idx[target]'s upper(r)-lower(l)
*/