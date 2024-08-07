#include<bits/stdc++.h>
using namespace std;
vector<string> v[105];
int dp[105][105];
const int INF=1e9;
int main(){
    string t;
    int n;
    cin>>t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        for(int j=0;j<a;j++){
            string s;
            cin>>s;
            v[i].emplace_back(s);
        }
    }

    //init
    for(int i=0;i<n;i++){
        for(int j=0;j<=t.length();j++){
            dp[i][j]=INF;
        }
    }

    dp[0][0]=0;
    //bag 0
    for(int i=0;i<v[0].size();i++){
        int len=v[0][i].length();
        if(t.substr(0,len)==v[0][i]){
            dp[0][len]=1;
        }
    }

    //bag 1-n-1
    for(int i=1;i<n;i++){   //now at bag i
        for(int j=0;j<v[i].size();j++){ //for each string in bag i
            int len=v[i][j].length();
            for(int k=0;k<i;k++){   //for each previous bag k
                for(int l=0;l<=t.length();l++){
                    if(l+len<=t.length() && t.substr(l,len) == v[i][j]){
                        dp[i][l+len]=min(dp[i][l+len], dp[k][l]+1);
                    }
                }
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[i][t.length()]);
    }
    if(ans==INF){
        printf("-1\n");
    }else{
        printf("%d\n",ans);
    }
    return 0;
}
/*
dp[i][j] = from bag 0-i, the min cost to make string T[0,j)
*/