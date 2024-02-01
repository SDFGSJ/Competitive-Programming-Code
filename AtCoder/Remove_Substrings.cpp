#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    if(s[0]!=s[n-1]){
        printf("1\n");
        return 0;
    }
    for(int i=0;i+1<n;i++){
        if(s[0]!=s[i] && s[i+1]!=s[n-1]){
            printf("2\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}