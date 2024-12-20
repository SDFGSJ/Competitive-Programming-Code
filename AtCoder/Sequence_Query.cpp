#include<bits/stdc++.h>
using namespace std;
multiset<long long> pos,neg;
long long calc(long long x,int k,int op){
    if(op==2){  //<=x
        auto it=neg.lower_bound(-x);
        if(it==neg.end()){
            return -1;
        }

        int i;
        for(i=1;i<k && next(it)!=neg.end();i++,it++){}
        if(i<k){
            return -1;
        }
        return -(*it);
    }else{  //>=x
        auto it=pos.lower_bound(x);
        if(it==pos.end()){
            return -1;
        }

        int i;
        for(i=1;i<k && next(it)!=pos.end();i++,it++){}
        if(i<k){
            return -1;
        }
        return *it;
    }
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        long long x;
        scanf("%d%lld",&op,&x);
        if(op==1){
            pos.emplace(x);
            neg.emplace(-x);
        }else{
            int k;
            scanf("%d",&k);
            printf("%lld\n",calc(x,k,op));
        }
    }
    return 0;
}
/*
multiset + lower/upper bound
*/