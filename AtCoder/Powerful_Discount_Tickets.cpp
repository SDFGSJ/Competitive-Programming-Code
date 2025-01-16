#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        pq.emplace(num);
    }

    for(int i=0;i<m;i++){
        int price=pq.top();pq.pop();
        pq.emplace(price/2);
    }

    long long sum=0;
    while(!pq.empty()){
        sum+=pq.top();pq.pop();
    }
    printf("%lld\n",sum);
    return 0;
}
/*
priority queue
the optimal strategy is to pick the max price and use a coupon on it, until all the coupons are used up
*/