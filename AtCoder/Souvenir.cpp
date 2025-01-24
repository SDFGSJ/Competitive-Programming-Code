#include<bits/stdc++.h>
using namespace std;
const int INF=1000;
int a[305];
char s[305][305];
pair<int,long long> dp[305][305];   //<# of flights, val>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]={INF,0};
        }
    }

    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        for(int j=1;j<=n;j++){
            if(s[i][j]=='Y'){   //i can go to j initially
                dp[i][j].first=1;
                dp[i][j].second=a[i]+a[j];
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int i2j_flight_cnt=dp[i][j].first, i2k2j_flight_cnt=dp[i][k].first + dp[k][j].first;
                long long cost=dp[i][k].second+dp[k][j].second-a[k];    //city k's souvenir is counted twice, need to substract once
                if(i2k2j_flight_cnt < i2j_flight_cnt){  //flight is shorter => update everything
                    dp[i][j]={dp[i][k].first + dp[k][j].first, cost};
                }else if(i2k2j_flight_cnt == i2j_flight_cnt){   //# of flight is same => take the max val of souvenir
                    dp[i][j].second=max(dp[i][j].second, cost);
                }
            }
        }
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        auto [num_of_flight,val]=dp[u][v];
        if(num_of_flight==INF){
            printf("Impossible\n");
        }else{
            printf("%d %lld\n",num_of_flight,val);
        }
    }
    return 0;
}
/*
Floyd warshall
dp[i][j] = (min # of flights, max souvenir val) from city i to city j

Note.
we can use
int dist[][] and long long val[][]
instead of
pair<int,long long> dp[][]
*/