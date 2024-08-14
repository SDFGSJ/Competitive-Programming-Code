#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool used[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }

    for(int i=m-1;i>=0;i--){
        if(!used[a[i]]){
            printf("%d\n",a[i]);
            used[a[i]]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            printf("%d\n",i);
        }
    }
    return 0;
}
/*
do it in reverse
the latest number will be at the top
*/