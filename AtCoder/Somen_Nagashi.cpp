#include<bits/stdc++.h>
using namespace std;
long long ans[200010];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> outque;   //<time,id>
priority_queue<int,vector<int>,greater<>> inque;  //<id>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++){
        inque.emplace(i);
    }

    for(int i=0;i<m;i++){
        int t,w,s;
        scanf("%d%d%d",&t,&w,&s);

        while(!outque.empty()){ //let the person out of queue return back to the queue before eating
            auto [time,id]=outque.top();
            if(time>t){
                break;
            }
            outque.pop();
            inque.emplace(id);
        }

        if(!inque.empty()){ //the person with the smallest id eats the noodle
            auto id=inque.top();inque.pop();
            ans[id]+=w;
            outque.emplace(t+s,id);
        }
    }

    for(int i=1;i<=n;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}
/*
priority queue
maintain 2 pq, 1 for person standing in the queue, the other for person outside the queue
*/