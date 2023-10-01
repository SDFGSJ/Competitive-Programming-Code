#include<bits/stdc++.h>
using namespace std;
char str[105];
int main(){
    int n,ans=-1,i;
    scanf("%d%s",&n,str);
    for(i=0;i+2<n;i++){
        if(str[i]=='A' && str[i+1]=='B' && str[i+2]=='C'){
            ans=i+1;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}