#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,int> um;    //<score,cnt>
long long point[200010];
int main(){
    int n,t;
    scanf("%d%d",&n,&t);
    um[0]=n;
    for(int i=0;i<t;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        um[point[a]]--;
        if(um[point[a]]==0){
            um.erase(point[a]);
        }
        point[a]+=b;
        um[point[a]]++;
        printf("%lld\n",(long long)um.size());
    }
    return 0;
}