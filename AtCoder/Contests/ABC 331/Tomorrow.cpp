#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,D,y,m,d,ansm=0,ansd=0;
    scanf("%d%d%d%d%d",&M,&D,&y,&m,&d);
    if(d+1>D){
        d=1;
        m++;
    }else{
        d++;
    }
    if(m>M){
        m=1;
        y++;
    }
    printf("%d %d %d",y,m,d);
    return 0;
}