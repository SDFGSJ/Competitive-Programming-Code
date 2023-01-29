#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,s,z,ans=0;
    scanf("%d%d",&k,&s);
    for(z=0;z<=k;z++){
        if(2*k>=s-z && s-z>=0){
            int num=min(k,s-z);
            ans+=(2*num-s+z+1);
        }
    }
    printf("%d",ans);
    return 0;
}
/*
x+y+z=s => x+y=s-z, z=0~k
x's max + y's max >= RHS && RHS>=0(since x,y,z>=0) => have sol

x + y = s-z
s-z-min(k,s-z) + min(k,s-z)
...
min(k,s-z) + s-z-min(k,s-z)

let num=min(k,s-z)
=> have num-(s-z-num)+1 = 2*num-s+z+1 sols
*/