#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> v;   //<strength,cost,idx>
bool bad[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int s,c;
        scanf("%d%d",&s,&c);
        v.emplace_back(s,c,i+1);
    }
    sort(v.begin(),v.end());
    int cnt=0,mincost=get<1>(v[n-1]);
    for(int i=n-2;i>=0;i--){    //start with the largest strength
        if(get<1>(v[i]) > mincost){ //any card's cost which is larger than mincost should be removed
            bad[get<2>(v[i])]=true; //remove this card
            cnt++;
        }else{
            mincost=get<1>(v[i]);
        }
    }
    printf("%d\n",n-cnt);
    for(int i=1;i<=n;i++){
        if(!bad[i]){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}