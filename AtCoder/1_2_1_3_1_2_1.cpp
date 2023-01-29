#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void seq(int n){
    if(n==1){
        ans.push_back(1);
        return;
    }
    seq(n-1);
    ans.push_back(n);
    seq(n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    seq(n);
    for(auto i:ans){
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}