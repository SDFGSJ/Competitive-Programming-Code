#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x,y;
    scanf("%d%d%d%d",&n,&k,&x,&y);
    printf("%d\n",min(n,k)*x+max(n-k,0)*y);
    return 0;
}