#include<bits/stdc++.h>
using namespace std;
int p[10][10010];
int cnt[80010]; //cnt[i] = size of good grid of number i
bool is_valid_col(vector<int>& rowidxs, int colidx){    //check whether all elements on that col is identical
    for(int i=0;i<rowidxs.size();i++){
        if(p[rowidxs[i]][colidx] != p[rowidxs[0]][colidx]){
            return false;
        }
    }
    return true;
}
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&p[i][j]);
        }
    }

    int ans=-1;
    for(int rowbit=1;rowbit<(1<<h);rowbit++){   //can skip rowbit=0
        vector<int> rowidxs;    //which rows are selected
        for(int i=0;i<h;i++){
            if(rowbit>>i&1){
                rowidxs.emplace_back(i);
            }
        }

        for(int i=1;i<=h*w;i++){
            cnt[i]=0;
        }

        for(int i=0;i<w;i++){
            if(is_valid_col(rowidxs,i)){    //all elements on col i is identical
                cnt[p[rowidxs[0]][i]]+=rowidxs.size();  //number p[rowidxs[0]][i] has good grid of size (rowidxs.size)*1
            }
        }

        for(int i=1;i<=h*w;i++){
            ans=max(ans,cnt[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}