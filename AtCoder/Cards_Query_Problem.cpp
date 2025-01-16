#include<bits/stdc++.h>
using namespace std;
multiset<int> box[200010];  //box[i] = set of balls in box i
set<int> ball[200010];  //ball[i] = set of boxes' idx that contain ball i
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    while(q--){
        int op,i;
        scanf("%d%d",&op,&i);
        if(op==1){
            int j;
            scanf("%d",&j);
            box[j].emplace(i);
            ball[i].emplace(j);
        }else if(op==2){
            for(auto num:box[i]){
                printf("%d ",num);
            }
            printf("\n");
        }else{
            for(auto num:ball[i]){
                printf("%d ",num);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
multiset + set
*/