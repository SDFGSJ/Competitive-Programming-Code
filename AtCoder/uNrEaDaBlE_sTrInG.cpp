#include<bits/stdc++.h>
using namespace std;
char str[1010];
int main(){
    int i;
    bool hard_to_read=true;
    scanf("%s",str+1);
    for(i=1;str[i]!='\0';i++){
        if(i%2==0 && !isupper(str[i])){
            hard_to_read=false;
        }
        if(i%2!=0 && !islower(str[i])){
            hard_to_read=false;
        }
    }

    if(hard_to_read){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}