#include<bits/stdc++.h>
using namespace std;
char str[100010];
int prefix[100010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int len,sum=0;
        long long cnt=0;
        scanf("%d%s",&len,str+1);
        map<int,int> mp;
        mp[0]=1;
        for(i=1;i<=len;i++){
            sum+=str[i]-'0';    //get the number
            prefix[i]=sum;
            mp[sum-i]++;    //sum - i => prefix sum - length
        }
        //x(x-1)=>C(x,2) Combination
        for(auto i:mp){
            cnt+=1ll*i.second*(i.second-1)/2;   
        }
        printf("%lld\n",cnt);
    }
    return 0;
}