#include<bits/stdc++.h>
using namespace std;
int a[100010];
int lowbit(int x){
    return x&-x;
}
class BIT{
    int n;
    vector<int> bit;
public:
    void init(int _n){
        n=_n;
        bit.resize(n);
        for(auto &b:bit){
            b=0;
        }
    }

    int query(int x){
        int sum=0;
        for(;x;x-=lowbit(x)){
            sum+=bit[x];
        }
        return sum;
    }
    void modify(int x,int val){
        for(;x<=n;x+=lowbit(x)){
            bit[x]+=val;
        }
    }
};
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    BIT bit;
    bit.init(n);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int pos,x;
            scanf("%d%d",&pos,&x);
            bit.modify(pos,x-a[pos]);
            a[pos]=x;
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",bit.query(r-1)-bit.query(l-1));
        }
    }
    return 0;
}