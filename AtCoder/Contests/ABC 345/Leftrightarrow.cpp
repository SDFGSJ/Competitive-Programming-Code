#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool good=true;
    if(s.length()<3){
        good=false;
    }else{
        if(s[0]!='<' || s[s.length()-1]!='>'){
            good=false;
        }
        for(int i=1;i<s.length()-1;i++){
            if(s[i]!='='){
                good=false;
            }
        }
    }
    if(good){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}