#include<bits/stdc++.h>
using namespace std;
unordered_set<int> us;
vector<int> ans;
bool isprime[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        us.emplace(num);
    }

    for(int i=1;i<=100000;i++){
        isprime[i]=true;
    }

    ans.emplace_back(1);
    for(int i=2;i<=m;i++){
        if(!isprime[i]){
            continue;
        }
        bool isans=true;
        for(int j=i;j<=100000;j+=i){
            isprime[j]=false;
            if(us.find(j)!=us.end()){
                isans=false;
            }
        }
        if(isans){
            ans.emplace_back(i);
        }
    }

    printf("%ld\n",ans.size());
    for(auto num:ans){
        printf("%d\n",num);
    }
    return 0;
}