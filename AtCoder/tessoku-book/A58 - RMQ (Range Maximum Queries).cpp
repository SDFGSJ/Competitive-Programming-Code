#include<bits/stdc++.h>
using namespace std;
int a[100010],seg[4*100010];
void pull(int id){
    seg[id]=max(seg[id*2], seg[id*2+1]);
}
void build(int l, int r, int id=1){
    if(l==r){
        seg[id]=a[l];
        return;
    }

    int m=(l+r)/2;
    build(l,m,2*id);
    build(m+1,r,2*id+1);
    pull(id);
}
int query(int ql,int qr,int l,int r,int id=1){
    if(qr<l || r<ql){
        return 0;
    }
    if(ql<=l && r<=qr){
        return seg[id];
    }
    int m=(l+r)/2;
    return max(query(ql,qr,l,m,id*2), query(ql,qr,m+1,r,id*2+1));
}
void update(int p,int val,int l,int r,int id=1){
    if(p<l || r<p){
        return;
    }
    if(l==r){
        seg[id]=val;
        return;
    }
    int m=(l+r)/2;
    update(p,val,l,m,id*2);
    update(p,val,m+1,r,id*2+1);
    pull(id);
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int pos,x;
            scanf("%d%d",&pos,&x);
            pos--;
            a[pos]=x;
            update(pos,x,0,n-1);
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            l--,r-=2;
            printf("%d\n",query(l,r,0,n-1));
        }
    }
    return 0;
}