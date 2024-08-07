#include<bits/stdc++.h>
using namespace std;
char grid[15][105],tmp[15][105];
int h,w;
int paint_col(int remain){
    //count how many '.' in each col
    vector<pair<int,int>> col;  //<# of '.', col idx>
    for(int j=0;j<w;j++){
        int cnt=0;
        for(int i=0;i<h;i++){
            cnt+=(tmp[i][j]=='.');
        }
        col.emplace_back(cnt,j);
    }

    //start picking from the col with most '.'
    sort(col.rbegin(),col.rend());
    for(int step=0;step<remain;step++){
        int col_idx=col[step].second;
        for(int i=0;i<h;i++){
            tmp[i][col_idx]='#';
        }
    }

    int result=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            result+=(tmp[i][j]=='#');
        }
    }
    return result;
}
int main(){
    int k;
    scanf("%d%d%d",&h,&w,&k);
    for(int i=0;i<h;i++){
        scanf("%s",grid[i]);
    }

    //enumerate all possible rows
    int ans=-1;
    for(int bit=0;bit<(1<<h);bit++){
        //init
        int remain=k;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                tmp[i][j]=grid[i][j];
            }
        }

        //check every bits
        for(int shift=0;shift<h;shift++){
            if(bit&(1<<shift)){
                for(int j=0;j<w;j++){
                    tmp[shift][j]='#';
                }
                remain--;
            }
        }

        if(remain>=0){
            ans=max(ans,paint_col(remain));
        }
    }
    printf("%d\n",ans);
    return 0;
}