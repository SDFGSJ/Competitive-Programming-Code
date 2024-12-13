#include<bits/stdc++.h>
using namespace std;
int lparent[500010],rparent[500010],color[500010],cnt[500010];
int find_boundary(int x,int* parent){
    if(x==parent[x]){
        return x;
    }
    int root=find_boundary(parent[x],parent);
    return parent[x]=root;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        lparent[i]=rparent[i]=color[i]=i;
        cnt[i]=1;
    }
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,c;
            scanf("%d%d",&x,&c);

            //find the leftmost & rightmost idx of the component containing x
            int left=find_boundary(x,lparent), right=find_boundary(x,rparent);
            cnt[color[left]]-=right-left+1;
            cnt[c]+=right-left+1;
            //always assign the correct color info to the leftmost idx
            color[left]=c;
            //find the leftmost idx of the component containing left-1
            if(left-1>=1 && color[find_boundary(left-1,lparent)]==c){
                lparent[left]=left-1;
                rparent[left-1]=left;
            }
            //we dont need to find the leftmost idx of the component containing right+1
            //because right+1 is just the leftmost idx of the component next to us
            if(right+1<=n && color[right+1]==c){
                lparent[right+1]=right;
                rparent[right]=right+1;
            }
        }else{
            int c;
            scanf("%d",&c);
            printf("%d\n",cnt[c]);
        }
    }
    return 0;
}
/*
https://atcoder.jp/contests/abc380/submissions/59848725
lparent[i] = leftmost idx of the component containing i
rparent[i] = rightmost idx of the component containing i
color[i] = color of node i
cnt[i] = # of node that has color i
*/