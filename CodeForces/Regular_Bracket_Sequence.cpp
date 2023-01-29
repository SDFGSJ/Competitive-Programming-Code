#include<bits/stdc++.h>
using namespace std;
char str[1000010];
stack<char> s;
int main(){
    int i,ans=0;
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            s.push(str[i]);
        }else{  //')'
            if(!s.empty() && s.top()=='('){
                ans+=2;
                s.pop();
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}