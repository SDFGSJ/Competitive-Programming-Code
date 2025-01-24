#include<bits/stdc++.h>
using namespace std;
queue<pair<long long,int>> q;   //<val,# of step>
bool vis[1000010];
int rotate(int val){
    int tmp=val,digit=0;
    while(tmp>0){
        tmp/=10;
        digit++;
    }

    int res=val%10;
    for(int i=1;i<=digit-1;i++){
        res*=10;
    }
    res+=val/10;
    return res;
}
int main(){
    int a,N;
    scanf("%d%d",&a,&N);

    int ans=-1;
    q.emplace(1,0);
    while(!q.empty()){
        auto [val,step]=q.front();q.pop();

        if(vis[val]){
            continue;
        }
        vis[val]=true;

        if(val==N){
            ans=step;
            break;
        }

        if(val*a<1000000){  //beware of overflow
            q.emplace(val*a,step+1);
        }
        if(val>=10 && val%10!=0){
            int num=rotate(val);
            q.emplace(num,step+1);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
bfs
since both operations would not change the # of digits of a num
so if num*a >= 1e6, there's no need to expand it further
*/