#include<bits/stdc++.h>
using namespace std;
vector<char> ans;
int main(){
    long long n;
    scanf("%lld",&n);
    while(n>0){
        n-=1;
        ans.emplace_back('a'+n%26);
        n/=26;
    }
    for(int i=ans.size()-1;i>=0;i--){
        printf("%c",ans[i]);
    }
    printf("\n");
    return 0;
}