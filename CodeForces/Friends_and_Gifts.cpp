#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool exist[200010];
set<int> empty_idx,empty_num,same_place_num;
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        exist[a[i]]=true;
        if(a[i]==0){
            empty_idx.insert(i+1);
        }
    }
    for(i=1;i<=n;i++){
        if(!exist[i]){
            empty_num.insert(i);
        }
    }

    //check if there's a number in both set,if it does then add it to same_place_num
    for(auto it=empty_idx.begin();it!=empty_idx.end();){
        if(empty_num.count(*it)>0){ //both in empty_idx and empty_num
            same_place_num.insert(*it);

            //notice the order of these two lines of code(iterator's position)
            empty_num.erase(*it);
            it=empty_idx.erase(it);
        }else{
            it++;
        }
    }

    if(same_place_num.size()==1){
        int idx = *same_place_num.begin();
        auto it=empty_num.end();  //take empty_num last number insert into same_place_num
        a[idx-1]=*(--it);   //remember to --it to access the last element

        same_place_num.clear();
        empty_num.erase(it);
        empty_num.insert(idx);  //move the only number in same_place_num to empty_num
    }else{  //size==0 || size>=2 same operation
        vector<int> ar,ar_idx;  //turn the set into vector
        auto it=same_place_num.begin();
        for(i=0;i<same_place_num.size() && it!=same_place_num.end();i++,it++){
            ar.push_back(*it);
            ar_idx.push_back(*it);
        }
        
        for(i=1;i<ar.size();i++){   //right shift
            swap(ar[0],ar[i]);
        }
        for(i=0;i<ar.size();i++){   //fill in the numbers
            a[ ar_idx[i]-1 ]=ar[i];
        }
    }

    //dealing with empty_num,empty_place and fill in the numbers
    auto it_idx=empty_idx.begin(),it_num=empty_num.begin();
    for(;it_idx!=empty_idx.end() && it_num!=empty_num.end();it_idx++,it_num++){
        a[ (*it_idx)-1 ] = (*it_num);
    }

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}