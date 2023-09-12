#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(){
    int n,i;
    string str;
    bool good=true;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>str;
        if(str[0]!='H' && str[0]!='D' && str[0]!='C' && str[0]!='S'){
            good=false;
            break;
        }
        if(str[1]!='A' && str[1]!='2' && str[1]!='3' && str[1]!='4' && str[1]!='5' && 
            str[1]!='6' && str[1]!='7' && str[1]!='8' && str[1]!='9' && str[1]!='T' && 
            str[1]!='J' && str[1]!='Q' && str[1]!='K'){
            good=false;
            break;
        }
        s.insert(str);
    }

    if(good && s.size()==n){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}