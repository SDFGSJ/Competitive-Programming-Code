#include<bits/stdc++.h>
using namespace std;
int a[100010];
map<int,int> window;    //sliding window <num,cnt>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int l=0,ans=-1;
    for(int i=0;i<n;i++){
        if(window.find(a[i])==window.end()){    //not in window
            if(window.size()>=k){
                while(window.size()>=k){
                    window[a[l]]--;
                    if(window[a[l]]==0){
                        window.erase(a[l]);
                    }
                    l++;
                }
            }
        }
        window[a[i]]++;
        ans=max(ans,i-l+1);
    }
    printf("%d\n",ans);
    return 0;
}