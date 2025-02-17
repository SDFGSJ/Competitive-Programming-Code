#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    bool ok=false;
    if(a*b==c){
        ok=true;
    }else if(a*c==b){
        ok=true;
    }else if(b*c==a){
        ok=true;
    }
    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}