#include<bits/stdc++.h>
using namespace std;
vector<long long> bags[100010];
int n;
long long x,ans;
void dfs(int idx, long long prod){
    if(idx>n){  //finish collecting all the stones from n bags
        if(prod==x){
            ans++;
        }
        return;
    }
    for(auto num:bags[idx]){
        if(prod<=x/num){
            dfs(idx+1,prod*num);
        }else if(prod>x/num){   //prod * num would be too big, no need to expand further
            continue;
        }
    }
}
int main(){
    scanf("%d%lld",&n,&x);
    for(int i=1;i<=n;i++){
        int l;
        scanf("%d",&l);
        for(int j=0;j<l;j++){
            long long ai;
            scanf("%lld",&ai);
            bags[i].emplace_back(ai);
        }
    }

    dfs(1,1);
    printf("%lld\n",ans);
    return 0;
}
/*
dfs enumerate
to prevent overflow, use division instead of multiplication
"sum*a > X" is equal to "sum > X/a"
*/