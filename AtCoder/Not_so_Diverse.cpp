#include<bits/stdc++.h>
using namespace std;
int a[200010];
map<int,int> m; //<num, cnt>
vector<pair<int,int>> v;    //<cnt,num>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]]++;
    }

    int cnt=0;
    if(m.size()<=k){
        cnt=0;
    }else{
        for(auto [key,val]:m){
            v.emplace_back(val,key);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<m.size()-k;i++){
            cnt+=v[i].first;
        }
    }
    printf("%d\n",cnt);
    return 0;
}