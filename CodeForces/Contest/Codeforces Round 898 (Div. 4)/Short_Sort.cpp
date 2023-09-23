#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        string s;
        cin>>s;
        if(s=="bca" || s=="cab"){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}