#include<bits/stdc++.h>
using namespace std;
set<int> row[400010],col[400010];
void erase_point(int r,int c){
    row[r].erase(c);
    col[c].erase(r);
}
int main(){
    int h,w,q;
    scanf("%d%d%d",&h,&w,&q);

    for(int i=1;i<=h;i++){
        for(int j=0;j<=w+1;j++){    //0, w+1 work as dummy num
            row[i].emplace(j);
        }
    }

    for(int i=1;i<=w;i++){
        for(int j=0;j<=h+1;j++){    //0, h+1 work as dummy num
            col[i].emplace(j);
        }
    }

    for(int i=0;i<q;i++){
        int r,c;
        scanf("%d%d",&r,&c);
        auto rowiter=row[r].lower_bound(c);
        auto coliter=col[c].lower_bound(r);
        if(*rowiter==c){   //there's a wall at (r,c)
            erase_point(r,c);
        }else{
            int left=*prev(rowiter), right=*rowiter, up=*prev(coliter), down=*coliter;
            if(left!=0){  //left
                erase_point(r,left);
            }
            if(right!=w+1){  //right
                erase_point(r,right);
            }
            if(up!=0){  //up
                erase_point(up,c);
            }
            if(down!=h+1){  //down
                erase_point(down,c);
            }
        }
    }

    int ans=0;
    for(int i=1;i<=h;i++){
        ans+=row[i].size()-2;   //ignore dummy num
    }
    printf("%d\n",ans);
    return 0;
}