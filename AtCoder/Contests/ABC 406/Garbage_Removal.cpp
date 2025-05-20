#include<bits/stdc++.h>
using namespace std;
vector<int> row[200010],col[200010];
bool rowisempty[200010],colisempty[200010];
int xremove[200010],yremove[200010];
int main(){
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        row[x].emplace_back(y);
        col[y].emplace_back(x);
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            if(rowisempty[x]){
                printf("0\n");
            }else{
                printf("%ld\n",row[x].size()-xremove[x]);   //# of trash left = # of trash on row x initially - # of trash that has been removed on row x
                for(auto y:row[x]){ //the trash on col y has also been removed
                    yremove[y]++;
                }
                rowisempty[x]=true;
            }
        }else{
            int y;
            scanf("%d",&y);
            if(colisempty[y]){
                printf("0\n");
            }else{
                printf("%ld\n",col[y].size()-yremove[y]);
                for(auto x:col[y]){
                    xremove[x]++;
                }
                colisempty[y]=true;
            }
        }
    }
    return 0;
}
/*
row[i] = list of idx j that has trash at (i,j)
col[j] = list of idx i that has trash at (i,j)
rowisempty[i] = true if row i is empty(does not have trash)
colisempty[i] = true if col i is empty(does not have trash)
xremove[i] = # of trash that has been removed on row i
yremove[i] = # of trash that has been removed on col i
*/