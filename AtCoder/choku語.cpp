#include<bits/stdc++.h>
using namespace std;
char s[55];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    bool ok=true;
    for(int i=0;i<len;){
        if(s[i]=='o' || s[i]=='k' || s[i]=='u'){
            i++;
        }else if(s[i]=='c' && i+1<len && s[i+1]=='h'){
            i+=2;
        }else{
            ok=false;
            break;
        }
    }

    if(ok){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
/*
simulation
*/