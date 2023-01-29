#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
    map<int,int> x,y;
    for(i=0;i<3;i++){
        int n,m;
        scanf("%d%d",&n,&m);
        x[n]++,y[m]++;
    }
    for(auto [k,v]:x){
        if(v<2){
            printf("%d",k);
        }
    }
    for(auto [k,v]:y){
        if(v<2){
            printf(" %d",k);
        }
    }
    return 0;
}