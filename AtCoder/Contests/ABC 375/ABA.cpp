#include<bits/stdc++.h>
using namespace std;
char s[200010];
vector<long long> pos[30];
vector<long long> pre[30];
long long sum[30];
int main(){
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        pos[s[i]-'A'].emplace_back(i);
    }

    for(int i=0;i<26;i++){
        pre[i]=pos[i];

        for(int j=0;j<pos[i].size();j++){
            sum[i]+=pos[i][j];
        }

        for(int j=1;j<pre[i].size();j++){
            pre[i][j]=pre[i][j-1]+pos[i][j];
        }
    }

    long long ans=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<pos[i].size();j++){
            auto it=lower_bound(pos[i].begin(),pos[i].end(),pos[i][j]+2);
            if(it==pos[i].end()){
                continue;
            }
            int idx=it-pos[i].begin();
            if(idx<1){
                continue;
            }
            long long part_sum=sum[i]-pre[i][idx-1], start=(pos[i].size()-idx)*(pos[i][j]+1);
            ans+=(part_sum-start);
        }
    }
    printf("%lld\n",ans);
    return 0;
}