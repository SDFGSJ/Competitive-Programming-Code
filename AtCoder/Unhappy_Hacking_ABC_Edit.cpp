#include<bits/stdc++.h>
using namespace std;
char s[15];
int main(){
    int i;
    scanf("%s",s);

    vector<char> v;
    for(i=0;s[i]!='\0';i++){
        if(s[i]!='B'){
            v.push_back(s[i]);
        }else{
            if(!v.empty()){
                v.pop_back();
            }
        }
    }
    
    for(auto c:v){
        printf("%c",c);
    }
    return 0;
}