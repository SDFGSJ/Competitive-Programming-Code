#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;    //<start,end>
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++){
        int d;
        scanf("%d",&d);
        d%=(a+b);
        int start=(0-d+(a+b))%(a+b), end=(a-1-d+a+b)%(a+b);
        if(start>end){
            v.emplace_back(0,end);
            v.emplace_back(start,a+b-1);
        }else{
            v.emplace_back(start,end);
        }
    }

    sort(v.begin(),v.end());

    int cnt=0;
    for(auto [l,r]:v){
        while(!pq.empty() && pq.top()<l){
            pq.pop();
        }
        pq.emplace(r);
        if(pq.size()==n){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
/*
0-indexed: 1st day starts from idx 0 => holiday is 0 ~ A-1
possible range of day s.t. after di days is holiday = [0-di,A-1-di]
make the interval valid, meaning that the num must be in [0, a+b-1]
sort intervals asc
use sweep line to check if there are n intervals overlapping at a specific time
Note.
start>end happens when A=2, B=3 0 1 | 2 3 4 and [4,1] => split into 2 intervals [0,1] & [4,4]
*/