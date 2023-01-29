#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,num;
    int x,y;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d",&num);
            if(num==1){
                x=i,y=j;
                break;
            }
        }
    }
    printf("%d\n",abs(x-2)+abs(y-2));
    return 0;
}