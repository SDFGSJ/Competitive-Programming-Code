#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> um;  //<value,cnt>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        um[num]++;
    }

    int ans=0;
    for(auto [val,cnt]:um){
        if(val<cnt){
            ans+=cnt-val;
        }else if(val>cnt){
            ans+=cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
hash map
maintain the # of each value appears in a[] using hash map
since we can only remove elements from a[],
so if a value doesnt match with its cnt, then just remove those nums to make a[] a good seq
*/