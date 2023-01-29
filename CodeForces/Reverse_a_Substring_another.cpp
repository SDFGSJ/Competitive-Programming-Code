#include<bits/stdc++.h>
using namespace std;
char str[300010];
int main(){
    int len,i;
    scanf("%d%s",&len,str);
    for(i=0;i+1<len;i++){
        if(str[i]>str[i+1]){
            printf("YES\n");
            printf("%d %d\n",i+1,i+2);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}