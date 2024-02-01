#include<bits/stdc++.h>
using namespace std;
int a[300010];
bool appeared[300010];
vector<int> ans;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==-1){
            continue;
        }else{
            appeared[a[i]]=true;
        }
    }

    int start=0;
    for(int i=1;i<=n;i++){
        if(!appeared[i]){
            start=i;
        }
    }

    while(start!=-1){
        ans.emplace_back(start);
        start=a[start];
    }
    reverse(ans.begin(), ans.begin()+n);
    for(auto num:ans){
        printf("%d ",num);
    }
    printf("\n");
    return 0;
}