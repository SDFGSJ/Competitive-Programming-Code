#include<bits/stdc++.h>
using namespace std;
int l[200010],r[200010],ans[200010];
int main(){
    int n;
    scanf("%d",&n);
    long long lower=0,upper=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&l[i],&r[i]);
        ans[i]=l[i];    //set all num to lower bound at first
        lower+=l[i];
        upper+=r[i];
    }

    if(0<lower || upper<0){ //0 must be in [lower,upper] <=> has ans
        printf("No\n");
        return 0;
    }

    printf("Yes\n");
    for(int i=0;i<n && lower!=0;i++){
        if(lower+r[i]-l[i]<0){
            lower+=r[i]-l[i];   //add diff to lower
            ans[i]=r[i];
        }else{
            ans[i]=l[i]-lower;
            lower=0;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}