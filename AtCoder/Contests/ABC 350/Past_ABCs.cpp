#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int num=100*(s[3]-'0')+10*(s[4]-'0')+(s[5]-'0');
    if(num<350 && num!=316 && num!=0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}