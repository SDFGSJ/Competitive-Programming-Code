#include<bits/stdc++.h>
using namespace std;
int a[200010],cnt[1000010];
int dp[1000010][2];
int main(){
    int n,d,M=-1;   //M = max element in a[]
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        M=max(M,a[i]);
    }

    int ans=0;
    if(d==0){   //special case
        for(int i=0;i<=M;i++){  //for each number, we can only left 1 element of it
            if(cnt[i]>=1){
                ans+=(cnt[i]-1);
            }
        }
        printf("%d\n",ans);
        exit(0);
    }
    for(int i=0;i<=d-1;i++){
        vector<int> vec;    //vec=[cnt[i], cnt[i+d], cnt[i+2d]...]
        vec.emplace_back(0);    //for 1-indexed purpose
        for(int j=i;j<=M;j+=d){
            vec.emplace_back(cnt[j]);
        }
        for(int idx=1;idx<vec.size();idx++){
            if(vec[idx]==0){    //this element is not in a[]
                dp[idx][0]=dp[idx][1]=min(dp[idx-1][0],dp[idx-1][1]);
            }else{
                dp[idx][1]=min(dp[idx-1][0],dp[idx-1][1])+vec[idx];
                dp[idx][0]=dp[idx-1][1];
            }
        }
        ans+=min(dp[vec.size()-1][0],dp[vec.size()-1][1]);
    }
    printf("%d\n",ans);
    return 0;
}
/*
dp
dp[i][0/1] = consider vec[1..i], min # of elements to be removed s.t. vec[i] and vec[i+1] are not both >0, where we keep/remove vec[i]
since i would only have conflict with i+d, i+2d..., so we can divide a[i] into d groups (d=0,1...d-1) where group i = [i,i+d,i+2d...]
consider group i = [i,i+d,i+2d...], we want to find the min # of elements to be removed s.t. the number left does not have conflict
ex.
17 3
2 2 2 5 5 5 5 11 11 14 17 17 23 23 26 26 26
ans=6

consider group 2 = [2,5...], we want to know [cnt[2], cnt[5]...], so we prepare an array vec = [0(dummy), 3, 4, 0(cnt[8]), 2, 1, 2, 0(cnt[20]), 2, 3]
so the problem becomes "remove min elements in vec[] s.t. vec[i] and vec[i+1] are not both >0"
if we want to remove vec[i], then whether vec[i-1] is removed or not is not important, so we take the min(dp[i-1][0],dp[i-1][1]) and remove vec[i]
if we want to keep vec[i], then vec[i-1] must be removed, so the value of dp[i][0] comes from dp[i-1][1]
see top 20's code
check CP note point 61.
Editorial video watched
*/