#include<bits/stdc++.h>
using namespace std;
int a[200010];
set<int> sorted_a,mex;
unordered_map<int,int> um;  //<num,cnt>
void debug(int n){
    printf("mex=[");
    for(auto i:mex){
        printf("%d ",i);
    }
    printf("]\na=[");

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("]\num={");
    for(auto [k,v]:um){
        printf("%d:%d, ",k,v);
    }
    printf("}\n");
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sorted_a.emplace(a[i]);
        um[a[i]]++;
    }
    for(int i=0;mex.size()<10;i++){
        if(sorted_a.find(i)==sorted_a.end()){
            mex.emplace(i);
        }
    }

    for(int i=0;i<q;i++){
        //debug(n);
        int idx,x;
        scanf("%d%d",&idx,&x);
        idx--;

        auto it=mex.find(x);
        if(it!=mex.end()){
            mex.erase(it);
        }

        if(um[a[idx]]==1 && a[idx]!=x){
            mex.emplace(a[idx]);
        }else if(x==*mex.begin()){
            mex.erase(mex.begin());
            for(int i=*mex.rbegin();;i++){
                if(!um[i]){
                    mex.emplace(i);
                    break;
                }
            }
        }
        um[a[idx]]--;
        a[idx]=x;
        um[a[idx]]++;

        printf("%d\n",*mex.begin());
    }
    return 0;
}