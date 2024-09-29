#include<bits/stdc++.h>
using namespace std;
char s[15];
bool has_palin(int n,int k){  //return true if s contains palindrome with length k
    for(int i=0;i<=n-k;i++){
        bool haspalin=true;
        for(int l=i,r=i+k-1;l<=r;l++,r--){
            if(s[l]!=s[r]){
                haspalin=false;
                break;
            }
        }
        if(haspalin){
            return true;
        }
    }
    return false;
}
int main(){
    int n,k;
    scanf("%d%d%s",&n,&k,s);

    sort(s,s+n);
    int ans=0;
    do{
        if(!has_palin(n,k)){
            ans++;
        }
    }while(next_permutation(s,s+n));
    printf("%d\n",ans);
    return 0;
}