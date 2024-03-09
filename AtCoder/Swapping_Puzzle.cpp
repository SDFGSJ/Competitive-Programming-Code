#include<bits/stdc++.h>
using namespace std;
int h,w;
vector<int> a,b;
set<vector<int>> visited;
queue<pair<vector<int>,int>> q; //<matrix,step>
bool same(vector<int>& a,vector<int>& b){
    for(int i=0;i<h*w;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
vector<int> swaprow(vector<int> a,int r1,int r2){
    for(int i=0;i<w;i++){
        swap(a[r1*w+i],a[r2*w+i]);
    }
    return a;
}
vector<int> swapcol(vector<int> a,int c1,int c2){
    for(int i=0;i<h;i++){
        swap(a[w*i+c1],a[w*i+c2]);
    }
    return a;
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=0;i<h*w;i++){
        int num;
        scanf("%d",&num);
        a.emplace_back(num);
    }
    for(int i=0;i<h*w;i++){
        int num;
        scanf("%d",&num);
        b.emplace_back(num);
    }
    q.emplace(a,0);
    while(!q.empty()){
        auto [now,step]=q.front();q.pop();
        if(same(now,b)){    //goal
            printf("%d\n",step);
            return 0;
        }
        if(visited.find(now)!=visited.end()){
            continue;
        }
        visited.emplace(now);
        for(int i=0;i+1<h;i++){
            q.emplace(swaprow(now,i,i+1),step+1);
        }
        for(int i=0;i+1<w;i++){
            q.emplace(swapcol(now,i,i+1),step+1);
        }
    }
    printf("-1\n");
    return 0;
}