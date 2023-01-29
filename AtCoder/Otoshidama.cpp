#include<bits/stdc++.h>
using namespace std;
int n,y,a,b,c;
void solve(){
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=n-i;j++){
            if(9000*i + 4000*j == y-1000*n){
                a=i,b=j,c=n-i-j;
                return;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&y);
    a=b=c=-1;   //ans
    solve();
    printf("%d %d %d\n",a,b,c);
    return 0;
}