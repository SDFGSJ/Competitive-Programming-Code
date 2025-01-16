#include<bits/stdc++.h>
using namespace std;
map<int,set<int>> row,col;  //<idx,list of idx>
int main(){
    int h,w,sr,sc;
    scanf("%d%d%d%d",&h,&w,&sr,&sc);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int r,c;
        scanf("%d%d",&r,&c);
        row[r].emplace(0);
        row[r].emplace(c);
        row[r].emplace(w+1);
        col[c].emplace(0);
        col[c].emplace(r);
        col[c].emplace(h+1);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        char d;int l;
        scanf(" %c %d",&d,&l);
        if(d=='L'){
            if(row.find(sr)==row.end()){    //sr-th row doesnt have any wall => simply move
                sc=max(1,sc-l); //beware of boundary
                printf("%d %d\n",sr,sc);
                continue;
            }
            auto it=row[sr].lower_bound(sc);
            int left=*prev(it);
            int dist_to_wall=sc-left-1;
            int dist_to_move=min(dist_to_wall,l);
            sc-=dist_to_move;
        }else if(d=='R'){
            if(row.find(sr)==row.end()){
                sc=min(w,sc+l);
                printf("%d %d\n",sr,sc);
                continue;
            }

            auto it=row[sr].upper_bound(sc);
            int right=*it;
            int dist_to_wall=right-sc-1;
            int dist_to_move=min(dist_to_wall,l);
            sc+=dist_to_move;
        }else if(d=='U'){
            if(col.find(sc)==col.end()){
                sr=max(1,sr-l);
                printf("%d %d\n",sr,sc);
                continue;
            }

            auto it=col[sc].lower_bound(sr);
            int upper=*prev(it);
            int dist_to_wall=sr-upper-1;
            int dist_to_move=min(dist_to_wall,l);
            sr-=dist_to_move;
        }else{
            if(col.find(sc)==col.end()){
                sr=min(h,sr+l);
                printf("%d %d\n",sr,sc);
                continue;
            }

            auto it=col[sc].upper_bound(sr);
            int lower=*it;
            int dist_to_wall=lower-sr-1;
            int dist_to_move=min(dist_to_wall,l);
            sr+=dist_to_move;
        }
        printf("%d %d\n",sr,sc);
    }
    return 0;
}
/*
map
add dummy walls at the outermost of the grid i.e. {(r,c) | r=0 or H+1, c=0 or W+1}
row[r] is a list of col idx c s.t. there is a wall on (r,c)
col[c] is a list of row idx r s.t. there is a wall on (r,c)
to find the next/prev wall on r-th row, use upper/lower bound on row[r]
to find the lower/upper wall on c-th col, use upper/lower bound on col[c]
*/