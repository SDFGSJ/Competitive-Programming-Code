#include<bits/stdc++.h>
using namespace std;
int a[100010],ans[100010];
class cmp{
public:
    bool operator()(const pair<int,int>& A,const pair<int,int>& B){
        return a[A.second]/(double)A.first < a[B.second]/(double)B.first;
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;   //<denominator,group id>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        pq.emplace(1,i);
    }

    for(int i=0;i<k;i++){
        auto [deno,group] = pq.top();pq.pop();
        ans[group]++;
        pq.emplace(deno+1,group);
    }

    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}