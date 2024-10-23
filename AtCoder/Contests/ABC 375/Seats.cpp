#include<bits/stdc++.h>
using namespace std;
char str[200010];
int main(){
    int n;
    scanf("%d%s",&n,str);

    int cnt=0;
    for(int i=0;i+2<n;i++){
        if(str[i]=='#' && str[i+2]=='#' && str[i+1]=='.'){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}