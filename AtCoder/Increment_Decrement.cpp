#include<bits/stdc++.h>
using namespace std;
char str[105];
int main(){
    int len,num,mymax,i;
    scanf("%d%s",&len,str);
    num=mymax=0;
    for(i=0;i<len;i++){
        if(str[i]=='I'){
            num++;
        }else{
            num--;
        }
        mymax=max(mymax,num);
    }
    printf("%d\n",mymax);
    return 0;
}