#include<bits/stdc++.h>
using namespace std;
char str[105];
vector<char> front,back;
int main(){
    int n;
    scanf("%d%s",&n,str);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(str[i]=='('){
            cnt++;
        }else{
            if(cnt==0){
                front.emplace_back('(');
            }else{
                cnt--;
            }
        }
    }

    for(auto c:front){
        printf("%c",c);
    }
    printf("%s",str);
    for(int i=0;i<cnt;i++){
        printf(")");
    }
    printf("\n");
    return 0;
}