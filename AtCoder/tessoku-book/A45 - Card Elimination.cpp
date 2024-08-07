#include<bits/stdc++.h>
using namespace std;
char str[200010];
int main(){
    int n;char c;
    scanf("%d %c%s",&n,&c,str);

    int blue=0,red=0;
    for(int i=0;i<n;i++){
        if(str[i]=='B'){
            blue++;
        }else if(str[i]=='R'){
            red++;
        }
    }
    blue%=3;
    red%=3;
    char result;
    if(blue==0 && red==0){
        result='W';
    }else if(blue==0 && red==1){
        result='R';
    }else if(blue==0 && red==2){
        result='B';
    }else if(blue==1 && red==0){
        result='B';
    }else if(blue==1 && red==1){
        result='W';
    }else if(blue==1 && red==2){
        result='R';
    }else if(blue==2 && red==0){
        result='R';
    }else if(blue==2 && red==1){
        result='B';
    }else if(blue==2 && red==2){
        result='W';
    }
    if(result==c){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}