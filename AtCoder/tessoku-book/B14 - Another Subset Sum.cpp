#include<bits/stdc++.h>
using namespace std;
int a[35];
vector<int> g1,g2;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int group1=(n+1)/2, group2=n-group1;    //divide into 2 groups, then enumerate
    for(int i=0;i<(1<<group1);i++){
        int result=0;
        for(int j=0;j<group1;j++){  //group1 bits
            if((i>>j)&1){
                result+=a[j];
            }
        }
        g1.emplace_back(result);
    }

    for(int i=0;i<(1<<group2);i++){
        int result=0;
        for(int j=0;j<group2;j++){  //group2 bits
            if((i>>j)&1){
                result+=a[group1+j];
            }
        }
        g2.emplace_back(result);
    }

    sort(g2.begin(),g2.end());
    for(auto num:g1){
        auto it=lower_bound(g2.begin(),g2.end(),k-num);
        if(it!=g2.end() && *it+num==k){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}