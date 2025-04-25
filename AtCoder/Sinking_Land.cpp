#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int h,w;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
bool inque[1005][1005]; //inque[i][j]=true if grid (i,j) is in pq
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq; //<height,row,col>
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
int main(){
    int y;
    scanf("%d%d%d",&h,&w,&y);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf("%d",&a[i][j]);
            if(i==1 || j==1 || i==h || j==w){   //push the boundary cell into pq
                pq.emplace(a[i][j],i,j);
                inque[i][j]=true;
            }
        }
    }

    int wetcnt=0;   //maintain the # of grid that sunk into the sea
    for(int year=1;year<=y;year++){ //enumerate time from 1 to Y
        while(!pq.empty() && get<0>(pq.top())<=year){   //if height <= sea level, this grid is going to sink into the sea
            int h,r,c;
            tie(h,r,c)=pq.top();pq.pop();
            for(int i=0;i<4;i++){   //push the adj grid into pq
                int nr=r+dx[i],nc=c+dy[i];
                if(ingrid(nr,nc) && !inque[nr][nc]){
                    pq.emplace(a[nr][nc],nr,nc);
                    inque[nr][nc]=true;
                }
            }
            wetcnt++;   //(r,c) sinks into the sea
        }
        printf("%d\n",h*w-wetcnt);  //# of grid that is above sea level
    }
    return 0;
}
/*
priority queue
maintain a bool[][] to check whether (i,j) is in pq,
so we can guarantee that every grid (i,j) is pushed into/pop from pq at most once
*/