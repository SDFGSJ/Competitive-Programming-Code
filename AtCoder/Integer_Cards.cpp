#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> um;  //<val,cnt>
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        um[num]++;
    }

    for(auto [val,cnt]:um){
        pq.emplace(val,cnt);
    }

    for(int i=0;i<m;i++){
        int b,c;
        scanf("%d%d",&b,&c);
        while(pq.top().first<c && b>0){
            auto [val,cnt]=pq.top();pq.pop();
            if(b>=cnt){
                //printf("emplace val=%d cnt=%d\n",c,cnt);
                pq.emplace(c,cnt);
                b-=cnt;
                //printf("after emplacing b=%d\n",b);
            }else if(b<cnt){
                //printf("emplace (val,cnt)=(%d,%d) and (%d,%d)\n",c,b,val,cnt-b);
                pq.emplace(c,b);
                pq.emplace(val,cnt-b);
                b=0;
            }
        }
    }
    long long sum=0;
    while(!pq.empty()){
        auto [val,cnt]=pq.top();pq.pop();
        //printf("val=%d cnt=%d\n",val,cnt);
        sum+=1ll*val*cnt;
    }
    printf("%lld\n",sum);
    return 0;
}