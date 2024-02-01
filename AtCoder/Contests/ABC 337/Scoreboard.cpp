#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int sumx=0,sumy=0;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        sumx+=x;
        sumy+=y;
    }
    if(sumx>sumy){
        printf("Takahashi\n");
    }else if(sumy>sumx){
        printf("Aoki\n");
    }else{
        printf("Draw\n");
    }
    return 0;
}