#include<bits/stdc++.h>
using namespace std;
long long a[500010],diff[500010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    for(int i=1;i<=n;i++){
        diff[i]+=diff[i-1];
        if(a[i]+diff[i]>=n-i){  //i-th alien has enough stones to give (i+1)-th, ... n-th alien
            diff[i+1]++,diff[n+1]--;
            a[i]=a[i]+diff[i]-(n-i);
        }else{  //doesnt have enough stone, has 0 stone in the end
            diff[i+1]++,diff[i+1+a[i]+diff[i]]--;
            a[i]=0;
        }
        printf("%lld ",a[i]);
    }
    printf("\n");
    return 0;
}
/*
imos
for each alien, we focus on "how many stones to give away and to whom?"
diff[i] = imos array
for each i, we calculate & update imos array during the process
# of stones that the i-th alien has = a[i]+diff[i]
# of aliens after the i-th alien = n-i
*/