#include<bits/stdc++.h>
using namespace std;
pair<int,int> point[15];
bool visited[15];
double ans=INT_MAX;
int n;
double s,t;
int get_offset(int num){
    if(num%2){
        return -1;
    }else{
        return 1;
    }
}
double dist(int a,int b, int c,int d){
    int dx=a-c, dy=b-d;
    return sqrt(dx*dx + dy*dy);
}
void dfs(int idx,double cur,int cnt){
    if(cnt==n-1){
        ans=min(ans,cur);
        return;
    }

    auto [a,b]=point[idx];
    for(int i=0;i<2*n;i++){
        if(!visited[i]){
            int offset=get_offset(i);
            auto [c,d]=point[i];
            auto [e,f]=point[i+offset];
            visited[i]=visited[i+offset]=true;
            dfs(i+offset,cur+dist(a,b,c,d)/s+dist(c,d,e,f)/t,cnt+1);
            visited[i]=visited[i+offset]=false;
        }
    }
}
int main(){
    scanf("%d%lf%lf",&n,&s,&t);
    for(int i=0;i<2*n;i++){
        scanf("%d%d",&point[i].first,&point[i].second);
    }

    for(int i=0;i<2*n;i++){
        int offset=get_offset(i);

        auto [a,b]=point[i];
        auto [c,d]=point[i+offset];
        double cur=dist(0,0,a,b)/s;
        visited[i]=visited[i+offset]=true;
        dfs(i+offset,cur+dist(a,b,c,d)/t,0);
        visited[i]=visited[i+offset]=false;
    }
    printf("%.10f\n",ans);
    return 0;
}