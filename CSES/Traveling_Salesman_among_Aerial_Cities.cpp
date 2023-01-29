#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> a;   //<x,y,z>
int cost(int from,int to){
    auto [from_x,from_y,from_z] = a[from];
    auto [to_x,to_y,to_z] = a[to];

    return abs(to_x-from_x) + abs(to_y-from_y) + max(0,to_z-from_z);
}
int main(){
    int n,i,j,k;
    scanf("%d",&n);

    vector<vector<int>> dp(1<<n, vector<int>(n,1e9));
    /*
    dp[s][i] = min cost that visit s and the last visited city = i
    */
    for(i=0;i<n;i++){   //city 0 ~ city n-1
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a.emplace_back(x,y,z);
    }


    dp[0][0]=0; //base case:[empty set][city 0] = 0
    for(i=1;i<(1<<n);i++){  //try all subset, represent in binary form
        for(j=0;j<n;j++){   //for all cities
            if(i & (1<<j)){ //check whether city j is in set i
                for(k=0;k<n;k++){   //for all cities
                    //min(i -> j, i -> k -> j)
                    dp[i][j] = min(dp[i][j], dp[i-(1<<j)][k] + cost(k, j));
                }
            }
        }
    }

    printf("%d\n",dp[(1<<n)-1][0]); //[city {0,1,2,...n-1}][city 0]
    return 0;
}