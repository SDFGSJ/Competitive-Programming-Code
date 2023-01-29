#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int l,r,dist;   //dist:the distance between l and r(|r-l|)
        long long m,smaller_n,bigger_n,diff;    //diff:the difference between l*smaller_n,l*bigger_n and m
        scanf("%d%d%lld",&l,&r,&m);

        dist=r-l;
        //in order to get close to m,we choose i*(m/i) and i*(m/i + 1) and check if the diff <= dist
        for(i=l;i<=r;i++){  //have to try all number start from l,sometimes only try l won't get the answer
            smaller_n = m/i;
            bigger_n = m/i + 1;
            if(smaller_n > 0 && abs(m - i*smaller_n) <= dist){   //smaller_n must > 0
                diff = m - i*smaller_n;
                /*
                b and c don't have to start from i because we only care about the difference,
                using l can also prevent b,c out of bound
                */
                printf("%d %lld %d\n",i,l+abs(diff),l);
                break;
            }else if(abs(m - i*bigger_n) <= dist){
                diff = m - i*bigger_n;
                printf("%d %d %lld\n",i,l,l+abs(diff));
                break;
            }
        }
    }
    return 0;
}