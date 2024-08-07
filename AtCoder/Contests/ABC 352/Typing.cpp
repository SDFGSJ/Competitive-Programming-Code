#include<bits/stdc++.h>
using namespace std;
char s[200010],t[200010];
int main(){
    scanf("%s%s",s,t);
    int idx=0;
    for(int i=0;s[i]!='\0';i++){
        while(t[idx]!=s[i]){
            idx++;
        }
        printf("%d ",idx+1);
        idx++;
    }
    printf("\n");
    return 0;
}