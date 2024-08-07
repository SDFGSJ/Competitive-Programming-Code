#include<bits/stdc++.h>
using namespace std;
deque<int> de;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        de.emplace_back(num);
    }
    for(int i=0;i<q;i++){
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        x--,y--;
        if(t==1){
            swap(de[x],de[y]);
        }else if(t==2){
            int last=de.back();
            de.pop_back();
            de.push_front(last);
        }else{
            printf("%d\n",de[x]);
        }
    }
    return 0;
}