#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt;  //<val,cnt>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    for(int i=0;i<m;i++){
        int b,c;
        scanf("%d%d",&b,&c);    //choose at most b cards and change their number to c
        while(cnt.begin()->first < c && b>0){  //smallest element in a[] < c
            int quantity=cnt.begin()->second;
            if(b>=quantity){
                cnt.erase(cnt.begin());
                cnt[c]+=quantity;
                b-=quantity;
            }else{
                cnt.begin()->second-=b;
                cnt[c]+=b;
                b=0;
            }
        }
    }

    long long ans=0;
    for(auto [num,quan]:cnt){
        ans+=1ll*num*quan;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
greedy
maintain the cnt of number in a[]
replace the cards greedily
*/