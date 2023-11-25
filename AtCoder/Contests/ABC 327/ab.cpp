#include<bits/stdc++.h>
using namespace std;
char str[105];
int main(){
    int n;
    scanf("%d%s",&n,str);
    bool ok=false;
    for(int i=0;i+1<n;i++){
        if(str[i]=='a' && str[i+1]=='b'){
            ok=true;
        }
        if(str[i]=='b' && str[i+1]=='a'){
            ok=true;
        }
    }
    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}