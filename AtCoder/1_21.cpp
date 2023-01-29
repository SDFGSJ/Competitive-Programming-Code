#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,i;
    bool good=false;
    string a,b;
    cin>>a>>b;
    
    a+=b;
    num=stoi(a);
    for(i=1;i*i<=num;i++){
        if(i*i==num){
            good=true;
        }
    }

    if(good){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}