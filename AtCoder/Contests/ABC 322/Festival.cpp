#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> ans;
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }

    int ptr=0;
    for(i=1;i<=n;i++){
        if(i==a[ptr]){
            ans.push_back(0);
            ptr++;
        }else{
            ans.push_back(a[ptr]-i);
        }
    }

    for(auto i:ans){
        printf("%d\n",i);
    }
    return 0;
}