#include<bits/stdc++.h>
using namespace std;
char str[200010];
stack<pair<int,int>> s; //<char,idx>
int main(){
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        if(!s.empty() && s.top().first=='(' && str[i]==')'){
            printf("%d %d\n",s.top().second+1,i+1);
            s.pop();
        }else{
            s.emplace(str[i],i);
        }
    }
    return 0;
}