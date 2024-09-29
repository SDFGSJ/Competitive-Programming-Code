#include<bits/stdc++.h>
using namespace std;
int mypow(int exp){
    int result=1;
    for(int i=0;i<exp;i++){
        result*=3;
    }
    return result;
}
int main(){
    int m;
    scanf("%d",&m);
    vector<int> ans;
    for(int i=10;i>=0;){
        int num=mypow(i);
        if(num<=m){
            m-=num;
            ans.emplace_back(i);
        }else{
            i--;
        }
    }
    printf("%ld\n",ans.size());
    for(auto num:ans){
        printf("%d ",num);
    }
    printf("\n");
    return 0;
}