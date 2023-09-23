#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        int score=0;
        for(i=0;i<10;i++){
            scanf("%s",a[i]);
        }
        /*printf("===\n");
        for(i=0;i<10;i++){
            printf("%s\n",a[i]);
        }
        printf("===\n");*/
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if(a[i][j]=='X'){
                    if(i==0 || i==9 || j==0 || j==9){
                        score+=1;
                    }else if(i==1 || i==8 || j==1 || j==8){
                        score+=2;
                    }else if(i==2 || i==7 || j==2 || j==7){
                        score+=3;
                    }else if(i==3 || i==6 || j==3 || j==6){
                        score+=4;
                    }else{
                        score+=5;
                    }
                }
            }
        }
        printf("%d\n",score);
    }
    return 0;
}