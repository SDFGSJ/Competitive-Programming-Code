#include<bits/stdc++.h>
using namespace std;
set<int> dish[300010];  //dish[i] = a list of ingredients that are in dish i
vector<int> ingre[300010];  //ingre[i] = a list of dish ids that contains ingredient i
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int aij;
            scanf("%d",&aij);
            dish[i].emplace(aij);
            ingre[aij].emplace_back(i);
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        int b;
        scanf("%d",&b);
        for(auto dishid:ingre[b]){  //id of dishes that contain ingredient b
            dish[dishid].erase(b);  //remove the ingredient if he overcomes it
            if(dish[dishid].size()==0){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
set
maintain the information of:
dish i contains what ingredients?
which dish has ingredient i?
*/