#include<bits/stdc++.h>
using namespace std;
deque<int> de;
const int mod=998244353;
long long ten[600010];  //ten[i] = 10**i % mod
int main(){
    int q;
    scanf("%d",&q);

    ten[0]=1;
    for(int i=1;i<=600000;i++){
        ten[i]=(ten[i-1]*10)%mod;
    }

    long long ans=1;
    de.emplace_back(1);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            de.emplace_back(x);
            ans=(ans*10+x)%mod;
        }else if(op==2){
            int num=de.front(), expo=de.size()-1;
            de.pop_front();
            ans=(ans - (ten[expo]*num)%mod + mod)%mod;
        }else{
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
make good use of deque property
calculate modulo every time when adding/removing numbers
add a num to back => (number represented by deque)*10+num => (ans*10+num) % mod
remove a num at front => (ans-num*10**(size-1)) % mod
*/