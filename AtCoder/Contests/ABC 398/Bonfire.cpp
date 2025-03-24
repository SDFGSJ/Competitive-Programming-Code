#include<bits/stdc++.h>
using namespace std;
char s[200010];
int ver[200010],hor[200010];
set<pair<int,int>> vis; //<row,col>
int main(){
    int n,r,c;
    scanf("%d%d%d%s",&n,&r,&c,s+1);
    for(int i=1;s[i]!='\0';i++){
        ver[i]=hor[i]=0;
        if(s[i]=='N'){
            ver[i]=-1;
        }else if(s[i]=='S'){
            ver[i]=1;
        }else if(s[i]=='E'){
            hor[i]=1;
        }else if(s[i]=='W'){
            hor[i]=-1;
        }
    }

    for(int i=1;i<=n;i++){
        ver[i]+=ver[i-1];
        hor[i]+=hor[i-1];
    }

    vis.emplace(ver[0],hor[0]);
    for(int i=1;i<=n;i++){
        int dr=ver[i]-r;
        int dc=hor[i]-c;

        if(vis.find({dr,dc})!=vis.end()){
            printf("1");
        }else{
            printf("0");
        }
        vis.emplace(ver[i],hor[i]);
    }
    printf("\n");
    return 0;
}
/*
prefix sum
since there will always have smoke at (0,0) after each operation
suppose the smoke generated at (0,0) after the i-th operation is smoke i
then for each time t=1,2...N, we want to know if smoke i (i<t) can reach (R,C) by performing s[i..t]
so we need to find an idx s.t. ver[t]-ver[x]=r and hor[t]-hor[x]=c
=> ver[x]=ver[t]-r and hor[x]=hor[t]-c
so check whether (ver[x], hor[x]) exists before time t using set<pair<int,int>>
*/