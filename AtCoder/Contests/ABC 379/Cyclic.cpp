#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a=n/100,b=n/10%10,c=n%10;
    printf("%d %d\n",100*b+10*c+a,100*c+10*a+b);
    return 0;
}