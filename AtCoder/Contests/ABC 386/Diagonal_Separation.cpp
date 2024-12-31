#include<bits/stdc++.h>
using namespace std;
tuple<int,int,char> p[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;char c;
        scanf("%d%d %c",&x,&y,&c);
        p[i]=make_tuple(x,y,c);
    }

    sort(p,p+m);
    int white_min_y=2e9;
    for(int i=0;i<m;i++){
        int x,y;char c;
        tie(x,y,c)=p[i];
        if(c=='B'){
            if(white_min_y<=y){
                printf("No\n");
                return 0;
            }
        }else{
            white_min_y=min(white_min_y,y);
        }
    }
    printf("Yes\n");
    return 0;
}
/*
sort the points by x coordinate in asc order
so that when we focus on two points p_i and p_(i+1), it is guaranteed that p_i.x <= p_(i+1).x, we only have to care about y coordinate
we focus on the position of 'B', the ans is yes iff
for every 'B' whose coordinate is (r,c), there's no (i,j) s.t. 1<=i<=r && 1<=j<=c && (i,j) is 'W'
simply put, if (r,c) is 'B', there's no 'W' in the square formed by top-left corner (1,1) and bottom-right corner (r,c)
*/