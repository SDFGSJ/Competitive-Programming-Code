#include<bits/stdc++.h>
using namespace std;
char s[15];
int main(){
    int a,b;
    scanf("%s%d%d",s,&a,&b);
    a--,b--;
    char temp=s[a];
    s[a]=s[b];
    s[b]=temp;
    printf("%s",s);
    return 0;
}