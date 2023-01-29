#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1,s2;
    cin>>s1>>s2;
    
    if(s1==".#" && s2=="#."){
        printf("No\n");
    }else if(s1=="#." && s2==".#"){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}