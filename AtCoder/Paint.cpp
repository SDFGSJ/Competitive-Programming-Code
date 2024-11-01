#include<bits/stdc++.h>
using namespace std;
vector<int> oper[200010];
bool rowused[200010],colused[200010];
long long cnt[200010];
int main(){
    long long h,w;
    int m;
    scanf("%lld%lld%d",&h,&w,&m);
    for(int i=0;i<m;i++){
        int t,a,x;
        scanf("%d%d%d",&t,&a,&x);
        oper[i].emplace_back(t);
        oper[i].emplace_back(a);
        oper[i].emplace_back(x);
    }

    cnt[0]=h*w;
    int used_col_cnt=0, used_row_cnt=0;
    for(int i=m-1;i>=0;i--){
        int type=oper[i][0], idx=oper[i][1], color=oper[i][2];
        if(type==1){    //paint row idx with color
            if(rowused[idx]){   //if this row has been painted, ignore it
                continue;
            }
            rowused[idx]=true;
            cnt[color]+=w-used_col_cnt;
            cnt[0]-=w-used_col_cnt;
            used_row_cnt++;
        }else{
            if(colused[idx]){
                continue;
            }
            colused[idx]=true;
            cnt[color]+=h-used_row_cnt;
            cnt[0]-=h-used_row_cnt;
            used_col_cnt++;
        }
    }
    int kind=0;
    for(int i=0;i<=200000;i++){
        kind+=(cnt[i]>0ll);
    }
    printf("%d\n",kind);
    for(int i=0;i<=200000;i++){
        if(cnt[i]>0ll){
            printf("%d %lld\n",i,cnt[i]);
        }
    }
    return 0;
}
/*
store every operation and perform them from the back
need to know which rows, cols have been painted
maintain the #rows, #cols that have been painted
*/