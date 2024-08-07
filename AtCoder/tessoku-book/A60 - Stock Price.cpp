#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int>> ms;    //monotonic stack <price, day>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int price;
        scanf("%d",&price);
        while(!ms.empty() && ms.top().first<=price){
            ms.pop();
        }
        if(ms.empty()){
            printf("-1 ");
        }else{
            printf("%d ",ms.top().second+1);
        }
        ms.emplace(price,i);
    }
    printf("\n");
    return 0;
}