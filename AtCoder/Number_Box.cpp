#include<bits/stdc++.h>
using namespace std;
char grid[15][15];
int dir[3]={-1,0,1};
long long calc(int r,int c,int dx,int dy,int n){
    long long res=0;
    for(int i=0;i<n;i++){   //n steps
        res=res*10+(grid[r][c]-'0');
        r=(r+dx+n)%n;   //r+dx might <0
        c=(c+dy+n)%n;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",grid[i]);
    }

    long long ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(k==1 && l==1){
                        continue;
                    }
                    ans=max(ans,calc(i,j,dir[k],dir[l],n));
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
simulation
enumerate all 8 directions for all (r,c)
*/