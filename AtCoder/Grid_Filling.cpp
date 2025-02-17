#include<bits/stdc++.h>
using namespace std;
int grid[305][305],pre[305][305][305];
int cnt[305];
int main(){
    int H,W,N,h,w;
    scanf("%d%d%d%d%d",&H,&W,&N,&h,&w);
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            scanf("%d",&grid[i][j]);
            cnt[grid[i][j]]++;
        }
    }

    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            for(int num=1;num<=N;num++){
                pre[i][j][num]=pre[i-1][j][num]+pre[i][j-1][num]-pre[i-1][j-1][num]+(grid[i][j]==num);
            }
        }
    }

    //enumerate all top-left corners
    for(int r=1;r+h-1<=H;r++){
        for(int c=1;c+w-1<=W;c++){
            int res=0;
            for(int num=1;num<=N;num++){
                int in_area=pre[r+h-1][c+w-1][num]-pre[r-1][c+w-1][num]-pre[r+h-1][c-1][num]+pre[r-1][c-1][num];    //# of num inside rectangle area
                if(cnt[num]-in_area > 0){   //# of num outside rectangle > 0
                    res++;
                }
            }
            printf("%d ",res);
        }
        printf("\n");
    }
    return 0;
}
/*
2d prefix sum
pre[i][j][num] = # of num in the rectangle whose top-left=(1,1) and bottom-right=(i,j)
*/