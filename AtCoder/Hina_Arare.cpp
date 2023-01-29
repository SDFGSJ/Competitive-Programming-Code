#include<bits/stdc++.h>
using namespace std;
set<char> s;
int main(){
    int n,i;
    char ch;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c",&ch);
        s.insert(ch);
    }
    if(s.size()==3){
        printf("Three\n");
    }else{
        printf("Four\n");
    }
    return 0;
}