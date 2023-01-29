#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    char str[10];
    scanf("%d of %s",&num,str);
    //2016 is leap year
    if(str[0]=='w'){
        if(num==5 || num==6){
            printf("53\n");
        }else{
            printf("52\n");
        }
    }else{
        if(num==30){
            printf("11\n");
        }else if(num==31){
            printf("7\n");
        }else{
            printf("12\n");
        }
    }
    return 0;
}
