#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int>> de;
int main(){
    int n;
    scanf("%d",&n);

    de.emplace_back(0,0);
    for(int i=0;i<n;i++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        de.emplace_back(x,y);
    }
    de.emplace_back(0,0);

    long double ans=0;
    for(int i=0;i+1<de.size();i++){
        long long dx=de[i+1].first-de[i].first;
        long long dy=de[i+1].second-de[i].second;
        ans+=sqrt(dx*dx+dy*dy);
    }
    printf("%.10Lf\n",ans);
    return 0;
}