#include<bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    int cnt=0;
    for(int i=0;s[i]!='\0';){
        if(s[i]=='0'){
            if(i+1<len && s[i+1]=='0'){
                cnt++;
                i+=2;
            }else{
                cnt++;
                i++;
            }
        }else{
            cnt++;
            i++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}