#include<bits/stdc++.h>
using namespace std;
int h[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }

    stack<int> s;
    vector<int> ans;
    for(int i=n-1;i>=1;i--){
        while(!s.empty() && s.top()<h[i]){
            s.pop();
        }
        s.emplace(h[i]);
        ans.emplace_back(s.size());
    }

    for(int i=ans.size()-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    printf("0\n");
    return 0;
}
/*
desc monotonic stack
*/