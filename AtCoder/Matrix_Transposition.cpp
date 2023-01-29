#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w,i,j;
    scanf("%d%d",&h,&w);
    vector<vector<int>> ans(w,vector<int>(h));

    int num;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf("%d",&num);
            ans[j][i]=num;
        }
    }

    for(i=0;i<ans.size();i++){
        for(j=0;j<ans[i].size();j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}