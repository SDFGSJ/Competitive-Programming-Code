#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    if(m==0){
        ans=1;
    }else if(n>=2*m){   //can be written as min(n,n-m)
        ans=m;
    }else{
        ans=n-m;
    }
    printf("%d\n",ans);
    return 0;
}