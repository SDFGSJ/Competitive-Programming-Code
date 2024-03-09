#include<bits/stdc++.h>
using namespace std;
int pos[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        pos[num]=i;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(pos[a]<pos[b]){
            printf("%d\n",a);
        }else{
            printf("%d\n",b);
        }
    }
    return 0;
}