#include<bits/stdc++.h>
using namespace std;
char s[30];
int pos[30];
int main(){
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        pos[s[i]-'A']=i;
    }

    int ans=0;
    for(int i=0;i+1<26;i++){
        ans+=abs(pos[i+1]-pos[i]);
    }
    printf("%d\n",ans);
    return 0;
}