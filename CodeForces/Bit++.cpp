#include<bits/stdc++.h>
using namespace std;
char str[5];
int main(){
    int t,num=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        if(str[1]=='+'){
            num++;
        }else{
            num--;
        }
    }
    printf("%d\n",num);
    return 0;
}