#include<bits/stdc++.h>
using namespace std;
int k;
int a[200010];
multiset<int> small,big;
void myinsert(int val){
    int cur_median = *small.rbegin();
    if(val > cur_median){   //insert into big
        big.insert(val);
        if(big.size() > k/2){   //maintain the heap size
            small.insert(*big.begin()); //move the smallest num in big to small
            big.erase(big.find(*big.begin()));
        }
    }else{
        small.insert(val);
        if(small.size() > (k+1)/2){ //k+1 since size(small)>=size(big)
            big.insert(*small.rbegin());    //move the biggest num in small to big
            small.erase(small.find(*small.rbegin()));
        }
    }
}
void myerase(int val){
    if(big.count(val)>0){
        big.erase(big.find(val));
    }else{
        small.erase(small.find(val));
    }

    //beware the size of small,big will never be empty so no worry
    if(small.empty()){
        small.insert(*big.begin());
        big.erase(big.find(*big.begin()));
    }

}
int main(){
    int n,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //the first window
    small.insert(a[0]);
    for(i=1;i<k;i++){
        myinsert(a[i]);
    }
    printf("%d ",*small.rbegin());


    for(i=k;i<n;i++){
        //have to judge k to avoid "when k=1 gets TLE"
        if(k!=1){
            myerase(a[i-k]);
            myinsert(a[i]);
        }else{
            /*if there's only 1 num in small(k=1) and we first erase it
            then when inserting new number, we cant find current median,
            since small is empty now
            */
            myinsert(a[i]);
            myerase(a[i-k]);
        }
        printf("%d ",*small.rbegin());
    }
    return 0;
}