#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        set<int> s;
        int n,k,m=1e9;  //m:min
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        for(auto num:s){
            int ans=0;
            for(i=0;i<n;){
                if(a[i]!=num){
                    i+=k;
                    ans++;
                }else{
                    i++;
                }
            }
            if(ans<m){
                m=ans;
            }
        }
        printf("%d\n",m);
    }
    return 0;
}