#include<bits/stdc++.h>
using namespace std;
int h[3010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }

    int ans=1;
    for(int i=1;i<=n;i++){  //starting idx
        for(int d=1;d<=n;d++){  //step
            int cnt=1;
            for(int j=i+d;j<=n;j+=d){
                if(h[i]==h[j]){
                    cnt++;
                }else{
                    break;
                }
            }
            ans=max(ans,cnt);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
brute force
enumerate every starting index, step and take max
*/