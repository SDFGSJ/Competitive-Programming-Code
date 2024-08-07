#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,z;
    scanf("%d%d%d%d",&n,&x,&y,&z);
    if((x<=z && z<=y) || x>=z && z>=y){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}