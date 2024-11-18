#include<bits/stdc++.h>
using namespace std;
deque<long long> de;    //easier to perform pop front and random access
long long imos[200010];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            de.emplace_back(0);
        }else if(op==2){
            int t;
            scanf("%d",&t);
            imos[0]+=t;
            imos[de.size()]-=t;
        }else{
            int h;
            scanf("%d",&h);
            if(imos[0]!=0){ //imos[0]!=0 <=> there exists type 2 before this type 3 operation
                for(int i=1;i<=de.size();i++){
                    imos[i]+=imos[i-1];
                }
                for(int i=0;i<de.size();i++){   //add the heights to plants and reset imos
                    de[i]-=imos[i];
                    imos[i]=0;
                }
            }
            int cnt=upper_bound(de.begin(),de.end(),-h)-de.begin();
            printf("%d\n",cnt);
            for(int i=0;i<cnt;i++){
                de.pop_front();
            }
        }
    }
    return 0;
}
/*
maintain a deque to put flower pot, and an array to do imos
type 1 => push 1 pot with height=0 into deque
type 2 => do imos
type 3 => sum up imos array, add them to deque and use upper bound, remove the plants whose height>=h
Note.
store the heights as neg number so that the deque is sorted asc, and the result of upper bound is correct
if imos[0] is 0, that means there's no type 2 operation before, so no need to sum up imos array
*/