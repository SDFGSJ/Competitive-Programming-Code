#include<bits/stdc++.h>
using namespace std;
long long a[200010];
pair<long long,long long> st[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        scanf("%lld%lld",&st[i].first,&st[i].second);
    }
    for(int i=0;i+1<n;i++){
        long long unit=a[i]/st[i].first;
        a[i+1]+=unit*st[i].second;
    }
    printf("%lld\n",a[n-1]);
    return 0;
}