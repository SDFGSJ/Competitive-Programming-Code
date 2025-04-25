#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((b-a)==(c-b)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}