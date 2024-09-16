#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n,total=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        total+=a[i];
    }

    if(total%n!=0){
        printf("-1\n");
        return 0;
    }

    int bridge=0,sum=0,goal=total/n;
    for(int i=1,cnt=1;i<=n;i++,cnt++){  //cnt: the size of the current component
        sum+=a[i];
        if(sum!=cnt*goal){
            bridge++;
        }else{
            sum=0;
            cnt=0;
        }
    }
    printf("%d\n",bridge);
    return 0;
}