#include<bits/stdc++.h>
using namespace std;
int a[3010];
int main(){
    int n,dirty,i;
    bool no=false;
    scanf("%d%d",&n,&dirty);
    for(i=0;i<dirty;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+dirty);

    if(a[0]==1 || a[dirty-1]==n){
        no=true;
    }else{
        for(i=0;i+2<dirty;i++){
            if(a[i+2]-a[i+1]==1 && a[i+1]-a[i]==1){
                no=true;
                break;
            }
        }
    }
    if(no){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
}