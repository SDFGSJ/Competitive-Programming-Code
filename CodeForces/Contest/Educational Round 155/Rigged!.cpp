#include<bits/stdc++.h>
using namespace std;
int a[105],s[105],e[105];
int main(){
    int n,i;
    int t;
    scanf("%d",&t);
    while(t--){
        bool ok=true;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&s[i],&e[i]);
        }
        for(i=1;i<n;i++){
            if(s[i]==s[0] && e[i]>=e[0]){   // same strength but he can lift more
                ok=false;
            }
            if(s[i]>s[0] && e[i]>e[0]){ // if you can lift weight w, he can do it too(with more lifts)
                ok=false;
            }
        }
        if(ok){
            printf("%d\n",s[0]-1);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}