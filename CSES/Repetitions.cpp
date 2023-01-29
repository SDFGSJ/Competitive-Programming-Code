#include<bits/stdc++.h>
using namespace std;
char str[1000010];
int main(){
    int i,mymax=0,count=1;
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++){
        if(str[i]==str[i+1]){
            count++;
        }else{
            mymax=max(mymax,count);
            count=1;
        }
    }
    printf("%d\n",mymax);
    return 0;
}