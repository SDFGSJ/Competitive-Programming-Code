#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",k*(int)pow(k-1,n-1));
    return 0;
}