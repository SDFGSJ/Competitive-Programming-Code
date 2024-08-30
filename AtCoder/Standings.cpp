#include<bits/stdc++.h>
using namespace std;
pair<pair<long long,long long>,int> a[200010];  //<<a,b>,idx>
bool cmp(pair<pair<long long,long long>,int> l, pair<pair<long long,long long>,int> r){
    long long result=l.first.first*(r.first.first+r.first.second)-r.first.first*(l.first.first+l.first.second);
    if(result!=0){
        return result>0;
    }
    return l.second<r.second;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a[i].first.first,&a[i].first.second);
        a[i].second=i;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        printf("%d ",a[i].second+1);
    }
    printf("\n");
    return 0;
}