#include<bits/stdc++.h>
using namespace std;
int p[300010],q[300010],ans[300010];
int color[300010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&q[i]);
        color[q[i]]=i;
    }

    for(int i=1;i<=n;i++){
        int person=color[i];    //the idx of the person who is wearing bib of number i
        int stareat=p[person];  //the idx of the person who "person_idx" is staring at
        ans[i]=q[stareat];  //the color of the bib of the person who is being stared at
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
/*
color[i] = the person id who is wearing bib of number i
*/