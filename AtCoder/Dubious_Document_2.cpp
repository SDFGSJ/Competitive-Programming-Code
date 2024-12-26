#include<bits/stdc++.h>
using namespace std;
char sp[55],t[55];
int pos=-1, splen, tlen;
void sp_match_t(){
    for(int i=0;i+tlen-1<=splen;i++){
        bool ok=true;
        for(int j=0;j<tlen;j++){
            if(sp[i+j]!='?' && sp[i+j]!=t[j]){  //skip '?' in S'
                ok=false;
                break;
            }
        }
        if(ok){ //if index i of S' matches T, remember this latest one
            pos=i;
        }
    }
}
int main(){
    scanf("%s%s",sp,t);
    splen=strlen(sp), tlen=strlen(t);
    sp_match_t();
    if(pos==-1){
        printf("UNRESTORABLE\n");
    }else{
        for(int i=0;sp[i]!='\0';i++){   //replace char in S'
            if(pos<=i && i<=pos+tlen-1){
                sp[i]=t[i-pos];
            }else{
                if(sp[i]=='?'){
                    sp[i]='a';
                }
            }
        }
        printf("%s\n",sp);
    }
    return 0;
}
/*
brute force
try matching T on every position of S'
if there are multiple possible positions, choose the latest one
if T can match S', replace the remaining '?' in S' with 'a'

Hack:
?b??
ab
*/