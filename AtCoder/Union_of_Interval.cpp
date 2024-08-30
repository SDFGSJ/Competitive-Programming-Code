#include<bits/stdc++.h>
using namespace std;
int pre[200010];
vector<int> l,r;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int L,R;
        scanf("%d%d",&L,&R);
        pre[L]++;pre[R]--;
    }

    for(int i=1;i<=200000;i++){
        pre[i]+=pre[i-1];
    }

    for(int i=0;i<=200000;i++){
        if(pre[i]==0 && pre[i+1]>=1){
            l.emplace_back(i+1);
        }else if(pre[i]>=1 && pre[i+1]==0){
            r.emplace_back(i+1);
        }
    }

    for(int i=0;i<l.size();i++){
        printf("%d %d\n",l[i],r[i]);
    }
    return 0;
}
//imos