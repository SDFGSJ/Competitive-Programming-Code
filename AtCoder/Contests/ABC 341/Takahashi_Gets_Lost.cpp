#include<bits/stdc++.h>
using namespace std;
char str[505],grid[505][505];
vector<pair<int,int>> land;
int main(){
    int h,w,n;
    scanf("%d%d%d%s",&h,&w,&n,str);
    for(int i=0;i<h;i++){
        scanf("%s",grid[i]);
        for(int j=0;j<w;j++){
            if(grid[i][j]=='.'){
                land.emplace_back(i,j);
            }
        }
    }

    int cnt=0;
    for(auto [r,c]:land){
        bool ok=true;
        for(int i=0;i<n;i++){
            if(str[i]=='R'){
                c+=1;
            }else if(str[i]=='U'){
                r-=1;
            }else if(str[i]=='L'){
                c-=1;
            }else{  //'D'
                r+=1;
            }
            if(!(0<=r && r<h && 0<=c && c<w) || grid[r][c]!='.' ){
                ok=false;
                break;
            }
        }
        if(ok){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}