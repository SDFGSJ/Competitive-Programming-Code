#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
    scanf("%s",s);
    int diff=0;
    int len=strlen(s);
    for(int i=0;i+1<len;i++){
        if(s[i]!=s[i+1]){
            diff++;
        }
    }
    printf("%d\n",diff);
    return 0;
}
/*
# of moves = # of idx i s.t. s[i]!=s[i+1], i = 1 ~ n-1
*/