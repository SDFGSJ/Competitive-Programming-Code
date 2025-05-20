#include<bits/stdc++.h>
using namespace std;
int row[90010],col[90010];  //(row[i], col[i]) = coordinate of number i
int main(){
    int h,w,d;
    scanf("%d%d%d",&h,&w,&d);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int num;
            scanf("%d",&num);
            num--;  //make 0<=num<=HW-1
            row[num]=i,col[num]=j;
        }
    }

    vector<vector<int>> vec(d); //vec[i] = list of costs when starting from i
    for(int num=0;num<=h*w-1;num++){
        if(vec[num%d].size()){  //calc manhattan dist of current number (num) and previous number (num-d)
            int prev_num=num-d,dr=abs(row[prev_num]-row[num]),dc=abs(col[prev_num]-col[num]);
            vec[num%d].emplace_back(vec[num%d].back()+dr+dc);   //prefix sum
        }else{  //starting point's cost = 0
            vec[num%d].emplace_back(0);
        }
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        l--,r--;
        int mod=l%d,r_term=(r-mod)/d,l_term=(l-mod)/d;  //l_term,r_term are 0-indexed
        printf("%d\n",vec[mod][r_term]-vec[mod][l_term]);
    }
    return 0;
}
/*
divide into D groups + prefix sum
for a starting number i, we can reach i+D,i+2D..., so we can divide HW numbers into D groups based on their modular under mod D
*/