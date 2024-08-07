#include<bits/stdc++.h>
using namespace std;
char str[200010];
int main(){
    int n;
    scanf("%d%s",&n,str);
    for(int i=0;i+2<n;i++){
        if(str[i]==str[i+1] && str[i+1]==str[i+2]){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}