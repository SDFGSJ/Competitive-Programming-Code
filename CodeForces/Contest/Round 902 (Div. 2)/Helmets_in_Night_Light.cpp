#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;    //<cost,people>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long sum=0ll;
        int people=0;   //# of people you have helped
        int n,p;
        scanf("%d%d",&n,&p);
        v.resize(n);
        for(int i=0;i<n;i++){
            scanf("%d",&v[i].second);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&v[i].first);
        }
        sort(v.begin(),v.end());    //start from the smallest cost
        /*for(auto p:v){
            printf("(%d,%d)\n",p.first,p.second);
        }*/

        sum+=p;people+=1;
        for(int i=0;i<n;i++){
            if(people<n){
                if(v[i].first<p){
                    sum += (long long)v[i].first * min(v[i].second, n-people);
                    people += min(v[i].second, n-people);
                }
            }
            //printf("people=%d, sum=%lld\n",people,sum);
        }
        sum+=(long long)(n-people)*p;
        printf("%lld\n",sum);
    }
    return 0;
}