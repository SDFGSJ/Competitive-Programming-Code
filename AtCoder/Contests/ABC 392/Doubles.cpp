#include<bits/stdc++.h>
using namespace std;
int face[105];
unordered_map<int,int> dices[105];  //<value,cnt>
double calc_prob(int idx1,int idx2){
    double res=0;
    for(auto [point,cnt]:dices[idx1]){
        if(dices[idx2].find(point)!=dices[idx2].end()){ //dice2 also has this point
            int cnt2=dices[idx2][point];
            res+=(1.0*cnt/face[idx1])*(1.0*cnt2/face[idx2]);
        }
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&face[i]);
        for(int j=0;j<face[i];j++){
            int num;
            scanf("%d",&num);
            dices[i][num]++;
        }
    }

    double ans=0;
    for(int dice1=0;dice1<n;dice1++){
        for(int dice2=dice1+1;dice2<n;dice2++){
            ans=max(ans,calc_prob(dice1,dice2));
        }
    }
    printf("%.12f\n",ans);
    return 0;
}
/*
brute force enumeration
face[i] = # of faces of die i
dices[i] = (value,cnt) pairs of die i
*/