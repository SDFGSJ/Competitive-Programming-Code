#include<bits/stdc++.h>
using namespace std;
char str[30];
int appear[30];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        bool no=false;
        int aidx=0;
        for(i=0;i<26;i++){
            appear[i]=0;
        }
        scanf("%s",str);
        int len=strlen(str);
        for(i=0;i<len;i++){
            appear[str[i]-'a']++;
        }
        for(i=0;i<26;i++){
            if(appear[i]>=2 || (appear[i]==0 && i<len)){
                printf("no\n");
                no=true;
                break;
            }
        }
        if(!no){
            for(i=0;i<26;i++){
                if(str[i]=='a'){
                    aidx=i;
                    break;
                }
            }
            for(i=aidx;i<len-1;i++){    //the right of 'a'
                if(str[i]>str[i+1]){
                    no=true;
                }
            }
            for(i=aidx;i>=1;i--){   //the left of 'a'
                if(str[i]>str[i-1]){
                    no=true;
                }
            }
            if(no){
                printf("no\n");
            }else{
                printf("yes\n");
            }
        }else{
            continue;
        }
    }
    return 0;
}