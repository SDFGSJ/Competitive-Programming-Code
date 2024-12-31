#include<bits/stdc++.h>
using namespace std;
char s[200010];
set<pair<int,int>> item;    //<x,y>
int h,k;
void update_health(int x,int y){
    auto it=item.find({x,y});
    if(it!=item.end() && h<k){
        h=k;
        item.erase(it); //consume this item
    }
}
int main(){
    int n,m;
    scanf("%d%d%d%d%s",&n,&m,&h,&k,s);
    for(int i=0;i<m;i++){
        int xi,yi;
        scanf("%d%d",&xi,&yi);
        item.emplace(xi,yi);
    }
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(s[i]=='U'){
            y+=1;
            h--;
        }else if(s[i]=='D'){
            y-=1;
            h--;
        }else if(s[i]=='L'){
            x-=1;
            h--;
        }else{
            x+=1;
            h--;
        }
        if(h<0){
            printf("No\n");
            return 0;
        }
        update_health(x,y);
    }
    printf("Yes\n");
    return 0;
}
/*
simulation
check whether h<0 after each move
*/