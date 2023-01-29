#include<bits/stdc++.h>
using namespace std;
char str[100010];
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
            sum+=str[i]-'0';
            cnt+=mp[sum-i];
            mp[sum-i]++;
        }
        printf("%lld\n",cnt);
    }
    return 0;
}