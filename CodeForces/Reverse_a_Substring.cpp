#include<bits/stdc++.h>
using namespace std;
char sorted[300010],origin[300010];
int main(){
    int len,i;
    scanf("%d%s",&len,sorted);
    
    memcpy(origin,sorted,len+5);
    sort(sorted,sorted+len);
    
    string s1=sorted,s2=origin;

    if(s1==s2){
        printf("NO\n");
    }else{
        printf("YES\n");
        for(i=0;i+1<len;i++){
            if(origin[i]>origin[i+1]){
                printf("%d %d\n",i+1,i+2);
                break;
            }
        }
    }
    return 0;
}