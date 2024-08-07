#include<bits/stdc++.h>
using namespace std;
char str[1000010];
vector<int> o,x;    //record the idx
int main(){
    int n;
    scanf("%d%s",&n,str);
    for(int i=0;i<n;i++){
        if(str[i]=='o'){
            o.emplace_back(i);
        }else{
            x.emplace_back(i);
        }
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        if(str[i]=='o'){
            auto it=lower_bound(x.begin(),x.end(),i);  //find the first 'x' after index i
            if(it!=x.end()){
                ans+=n-(*it);
            }
        }else{
            auto it=lower_bound(o.begin(),o.end(),i);
            if(it!=o.end()){
                ans+=n-(*it);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}