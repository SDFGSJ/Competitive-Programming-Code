#include<bits/stdc++.h>
using namespace std;
char s[15];
int s_cnt[10];
bool same_distri(long long num,int n){
    int num_cnt[10]={0},digit=0;
    while(num>0){
        num_cnt[num%10]++;
        num/=10;
        digit++;
    }

    if(digit<n){
        num_cnt[0]+=n-digit;    //not '='
    }

    for(int i=0;i<10;i++){
        if(s_cnt[i]!=num_cnt[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    scanf("%d%s",&n,s);

    for(int i=0;i<n;i++){
        s_cnt[s[i]-'0']++;
    }

    int ans=0;
    for(long long i=0;i<=1e7;i++){
        if(same_distri(i*i,n)){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
simply check the distribution of the numbers of i*i
*/