#include<bits/stdc++.h>
using namespace std;
//char s[100010];
string s;
vector<string> pattern;
int main(){
    //scanf("%s",s);
    cin>>s;
    pattern.emplace_back(s);
    for(int i=0;i<3;i++){
        char ch=pattern[i][0];
        if(ch=='A'){
            pattern.emplace_back("BC");
        }else if(ch=='B'){
            pattern.emplace_back("CA");
        }else{
            pattern.emplace_back("AB");
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        long long t,k;
        scanf("%lld%lld",&t,&k);
        k--;
        while(t>=1 && k>=2){
            k/=2;
            t--;
        }

        char ans;
        if(t==0){
            ans=pattern[t][k];
        }else{
            ans=pattern[(t-1)%3+1][k];
        }
        printf("%c\n",ans);
    }
    return 0;
}