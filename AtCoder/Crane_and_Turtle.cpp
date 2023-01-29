#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    scanf("%d%d",&x,&y);

    if(y-2*x >= 0 && 4*x-y >= 0 && (y-2*x)%2==0 && (4*x-y)%2==0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}