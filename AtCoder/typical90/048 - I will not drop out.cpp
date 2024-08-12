#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v.emplace_back(b);
        v.emplace_back(a-b);
    }
    sort(v.rbegin(),v.rend());
    long long ans=0;
    for(int i=0;i<k;i++){
        ans+=v[i];
    }
    printf("%lld\n",ans);
    return 0;
}