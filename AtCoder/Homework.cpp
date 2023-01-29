#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,work=0,i;
    scanf("%d%d",&n,&m);

    int num;
    for(i=0;i<m;i++){
        scanf("%d",&num);
        work+=num;
    }

    if(n<work){
        printf("-1");
    }else{
        printf("%d\n",n-work);
    }
    return 0;
}