#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int len,cnt=0;
        string s;
        cin>>len>>s;
        cnt=count(s.begin(), s.end(), '0');
        int num=cnt%2;
        if(cnt==1){
            printf("BOB\n");
        }else if(num==1){   //odd
            printf("ALICE\n");
        }else{  //even
            printf("BOB\n");
        }
    }
    return 0;
}