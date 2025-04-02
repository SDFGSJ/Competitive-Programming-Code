#include<bits/stdc++.h>
using namespace std;
int a[400010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<vector<int>> pos(n+5);   //pos[i] = list of idx of number i
        for(int i=1;i<=2*n;i++){
            scanf("%d",&a[i]);
            pos[a[i]].emplace_back(i);
        }

        set<pair<int,int>> ans;
        for(int i=1;i<=2*n;i++){
            if(i-1>=1 && a[i-1]!=a[i]){ //index i has left neighbor and that neighbor is not a[i]
                int lneigh=a[i-1],his_partner_idx=pos[lneigh][0]+pos[lneigh][1]-(i-1);
                if(abs(i-1 - his_partner_idx)==1){  //left neighbor and his partner are adjacent
                    continue;
                }
                if(his_partner_idx-1>=1 && his_partner_idx-1!=i && a[his_partner_idx-1]==a[i] && abs(his_partner_idx-1 - i)!=1){
                    //his partner has left neighbor
                    //his partner's left neightbor is not me
                    //his partner's left neighbor is my partner
                    //my partner is not adjacent to me
                    ans.emplace(min(a[i],lneigh), max(a[i],lneigh));
                }else if(his_partner_idx+1<=2*n && his_partner_idx+1!=i && a[his_partner_idx+1]==a[i] && abs(his_partner_idx+1 - i)!=1){
                    ans.emplace(min(a[i],lneigh), max(a[i],lneigh));
                }
            }else if(i+1<=2*n && a[i+1]!=a[i]){ //index i has right neighbor and that neighbor is not a[i]
                int rneigh=a[i+1],his_partner_idx=pos[rneigh][0]+pos[rneigh][1]-(i+1);
                if(abs(i+1 - his_partner_idx)==1){
                    continue;
                }
                if(his_partner_idx-1>=1 && his_partner_idx-1!=i && a[his_partner_idx-1]==a[i] && abs(his_partner_idx-1 - i)!=1){
                    ans.emplace(min(a[i],rneigh), max(a[i],rneigh));
                }else if(his_partner_idx+1<=2*n && his_partner_idx+1!=i && a[his_partner_idx+1]==a[i] && abs(his_partner_idx+1 - i)!=1){
                    ans.emplace(min(a[i],rneigh), max(a[i],rneigh));
                }
            }
        }
        printf("%d\n",(int)ans.size());
    }
    return 0;
}
/*
for each person, we only need to ask his left/right neighbor to change seats with that neighbor's partner in order to make 2 couples sit together
1. ask 1 of the neighbors where his/her partner is
2. if 1 of his/her partner's neighbors is my partner(can't be myself), then I can change seat with my neighbor's partner
3. beware that (me and my partner), (my neighbor and his/her partner) can not be adjcacent initially
*/