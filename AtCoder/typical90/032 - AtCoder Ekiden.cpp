#include<bits/stdc++.h>
using namespace std;
int a[15][15];
set<pair<int,int>> bad;
bool valid(int n,vector<int>& vec){
    for(int i=0;i+1<n;i++){
        auto it1=bad.find({vec[i], vec[i+1]});
        auto it2=bad.find({vec[i+1], vec[i]});
        if(it1!=bad.end() || it2!=bad.end()){
            return false;
        }
    }
    return true;
}
int cost(vector<int>& vec){
    int result=0;
    for(int i=0;i<vec.size();i++){
        result+=a[vec[i]][i];
    }
    return result;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        bad.emplace(x,y);
    }

    vector<int> permu;
    for(int i=0;i<n;i++){
        permu.emplace_back(i);
    }
    int ans=1e9;
    do{
        if(valid(n,permu)){
            ans=min(ans,cost(permu));
        }
    }while(next_permutation(permu.begin(), permu.end()));
    if(ans==1e9){
        printf("-1\n");
    }else{
        printf("%d\n",ans);
    }
    return 0;
}