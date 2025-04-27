#include<bits/stdc++.h>
using namespace std;
char t[20],u[20];
int main(){
    scanf("%s%s",t,u);
    int tlen=strlen(t),ulen=strlen(u);
    for(int i=0;i<tlen;i++){
        bool ok=true;
        for(int j=0;j<ulen;j++){
            if(t[i+j]!='?' && t[i+j]!=u[j]){
                ok=false;
            }
        }
        if(ok){
            printf("Yes\n");
            exit(0);
        }
    }
    printf("No\n");
    return 0;
}