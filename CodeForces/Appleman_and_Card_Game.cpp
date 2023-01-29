#include<bits/stdc++.h>
using namespace std;
char s[100010];
int cnt[30];
int main(){
    int n,k,i;
    long long ans=0;
    scanf("%d%d%s",&n,&k,s);

    for(i=0;s[i]!='\0';i++){
        cnt[s[i]-'A']++;
    }
    sort(cnt,cnt+30,greater<int>());

    i=0;
    while(k>0){
        long long num=min(cnt[i],k);
        ans+=num*num;
        k-=num;
        i++;
    }
    printf("%lld\n",ans);
    return 0;
}