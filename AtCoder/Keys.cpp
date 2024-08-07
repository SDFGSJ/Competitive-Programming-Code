#include<bits/stdc++.h>
using namespace std;
vector<int> test[105];
char result[105];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int c;
        scanf("%d",&c);
        for(int j=0;j<c;j++){
            int num;
            scanf("%d",&num);
            num--;
            test[i].emplace_back(num);
        }
        scanf(" %c",&result[i]);
    }

    int ans=0;
    for(int i=0;i<(1<<n);i++){
        bool ok=true;
        for(int j=0;j<m;j++){
            int cnt=0;
            for(auto num:test[j]){
                cnt+=((i>>num)&1);
            }
            if(cnt>=k && result[j]=='o'){
                continue;
            }
            if(cnt<k && result[j]=='x'){
                continue;
            }
            ok=false;
        }
        ans+=ok;
    }
    printf("%d\n",ans);
    return 0;
}