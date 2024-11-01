#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> s;
int dx[8]={2,1,-1,-2,-2,-1,1,2},dy[8]={1,2,2,1,-1,-2,-2,-1};
int main(){
    long long n;
    int m;
    scanf("%lld%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        s.emplace(a,b);
        for(int j=0;j<8;j++){
            int newx=a+dx[j], newy=b+dy[j];
            if(0<=newx && newx<n && 0<=newy && newy<n){
                s.emplace(newx,newy);
            }
        }
    }
    printf("%lld\n",n*n-1ll*s.size());
    return 0;
}