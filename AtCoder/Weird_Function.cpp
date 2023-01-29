#include<bits/stdc++.h>
using namespace std;
int f(int x){
    return x*x+2*x+3;
}
int main(){
    int t;
    scanf("%d",&t);
    printf("%d\n",f(f(f(t)+t)+f(f(t))));
    return 0;
}