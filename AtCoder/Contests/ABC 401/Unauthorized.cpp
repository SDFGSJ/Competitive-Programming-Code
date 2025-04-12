#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    bool login=false;
    int cnt=0;
    for(int i=0;i<n;i++){
        string op;
        cin>>op;
        if(op=="login"){
            login=true;
        }else if(op=="logout"){
            login=false;
        }else if(op=="public"){

        }else{
            if(!login){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}