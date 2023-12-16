#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    if(s[0]>s[1]){
        swap(s[0],s[1]);
    }
    if(t[0]>t[1]){
        swap(t[0],t[1]);
    }
    //printf("s2-s1=%d,t2-t1=%d\n",s[1]-'A'-(s[0]-'A'),t[1]-'A'-(t[0]-'A'));
    if(s[1]-s[0]==t[1]-t[0] || s[1]-s[0]+t[1]-t[0]==5){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}