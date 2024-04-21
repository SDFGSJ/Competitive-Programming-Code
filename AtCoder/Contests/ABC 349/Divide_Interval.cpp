#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> ans;
void query(long long ql,long long qr,long long l,long long r){
    if(qr<=l || r<=ql){
        return;
    }
    if(ql<=l && r<=qr){
        ans.emplace_back(l,r);
        return;
    }
    long long m=l+(r-l)/2;
    query(ql,qr,l,m);
    query(ql,qr,m,r);
}
int main(){
    long long l,r;
    scanf("%lld%lld",&l,&r);
    query(l,r,0,1ll<<60);   //not (1<<60)+1
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%lld %lld\n",ans[i].first,ans[i].second);
    }
    return 0;
}