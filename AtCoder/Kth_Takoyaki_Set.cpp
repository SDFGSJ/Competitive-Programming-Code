#include<bits/stdc++.h>
using namespace std;
set<int> a; //remove duplicate number
vector<long long> arr;
unordered_set<long long> vis;
priority_queue<long long,vector<long long>,greater<long long>> pq;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        a.emplace(num);
    }

    pq.emplace(0);
    while(arr.size()<k+1){
        long long num=pq.top();pq.pop();
        if(vis.find(num)!=vis.end()){   //this number is already in arr
            continue;
        }
        arr.emplace_back(num);
        vis.emplace(num);
        for(auto cost:a){
            pq.emplace(num+cost);
        }
    }
    printf("%lld\n",arr[k]);
    return 0;
}
/*
priority queue, first push 0 to pq, take top and push top+a[i] back
push the smallest num to vector until size>=k+1, mark the number emplaced as visited
the ans is vector[k], since vector[0] is 0
*/