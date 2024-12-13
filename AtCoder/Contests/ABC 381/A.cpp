#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int n;
    scanf("%d%s",&n,s+1);
    bool isans=true;
    if(n%2){
        for(int i=1;i<=(n+1)/2-1;i++){
            if(s[i]!='1'){
                isans=false;
            }
        }
        if(s[(n+1)/2]!='/'){
            isans=false;
        }
        for(int i=(n+1)/2+1;i<=n;i++){
            if(s[i]!='2'){
                isans=false;
            }
        }
    }else{
        isans=false;
    }
    if(isans){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}