#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        int h,w;    //i,j
        scanf("%d%d",&h,&w);
        for(i=0;i<h;i++){
            if(i==0 || i==h-1){
                if(i==0){
                    for(j=0;j<w;j++){
                        if(j%2==0){
                            printf("1");
                        }else{
                            printf("0");
                        }
                    }
                }else{  //i==h-1
                    if(h>2){
                        for(j=0;j<w;j++){
                            if(j%2==0){
                                printf("1");
                            }else{
                                printf("0");
                            }
                        }
                    }else{
                        for(j=0;j<w;j++){
                            printf("0");
                        }
                    }
                }
            }else{  //the line between top and bottom
                if(i%2==1 || (h%2==0 && i==h-2)){
                    for(j=0;j<w;j++){
                        printf("0");
                    }
                }else{  //100...0001
                    printf("1");
                    for(j=0;j<w-2;j++){
                        printf("0");
                    }
                    if(w>2){
                        printf("1");
                    }else{
                        printf("0");
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}