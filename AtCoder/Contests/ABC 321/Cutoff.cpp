#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
    int n,x,i,score;
    bool ok=false;
    scanf("%d%d",&n,&x);
    for(i=0;i<n-1;i++){
        scanf("%d",&a[i]);
    }

    for(score=0;score<=100;score++){
        int sum=0;
        ok=false;
        for(i=0;i<n-1;i++){
            b[i]=a[i];
        }
        b[n-1]=score;
        sort(b,b+n);
        for(i=1;i<=n-2;i++){
            sum+=b[i];
        }
        if(sum>=x){
            ok=true;
            break;
        }
    }
    if(ok){
        printf("%d\n",score);
    }else{
        printf("-1\n");
    }
    return 0;
}