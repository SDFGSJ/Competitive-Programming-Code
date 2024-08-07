#include<bits/stdc++.h>
using namespace std;
int delta[200010],price[200010];
int main(){
    int d,x;
    scanf("%d%d",&d,&x);
    price[1]=x;
    for(int i=2;i<=d;i++){
        scanf("%d",&delta[i]);
        price[i]=price[i-1]+delta[i];
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int s,t;
        scanf("%d%d",&s,&t);
        if(price[s]>price[t]){
            printf("%d\n",s);
        }else if(price[s]<price[t]){
            printf("%d\n",t);
        }else{
            printf("Same\n");
        }
    }
    return 0;
}