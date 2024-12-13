#include<bits/stdc++.h>
using namespace std;
int num[9],arr[9]={0,1,2,3,4,5,6,7,8};
bool is_dissapointed(){
    vector<int> row[3],col[3],dia[2];
    for(int i=0;i<9;i++){
        int r=arr[i]/3,c=arr[i]%3;

        if(r==c){   //(r,c) is on the top-left bottom-right diagonal
            dia[0].emplace_back(num[arr[i]]);
        }
        if(r+c==2){ //top-right bottom-left diagonal
            dia[1].emplace_back(num[arr[i]]);
        }

        row[r].emplace_back(num[arr[i]]);
        if(row[r].size()==3 && row[r][0]==row[r][1] && row[r][1]!=row[r][2]){
            return true;
        }

        col[c].emplace_back(num[arr[i]]);
        if(col[c].size()==3 && col[c][0]==col[c][1] && col[c][1]!=col[c][2]){
            return true;
        }
    }
    if(dia[0][0]==dia[0][1] && dia[0][1]!=dia[0][2]){
        return true;
    }
    if(dia[1][0]==dia[1][1] && dia[1][1]!=dia[1][2]){
        return true;
    }
    return false;
}
int main(){
    for(int i=0;i<9;i++){
        scanf("%d",&num[i]);
    }

    int cnt=0;
    do{
        if(is_dissapointed()){
            cnt++;
        }
    }while(next_permutation(arr,arr+9));
    printf("%.20lf\n",(double)(362880-cnt)/362880); //9! is 362880
    return 0;
}
/*
next permutation
maintain the numbers that have been visited on each row,col,diagonal
row[i] = list of numbers that have been visited on the i-th row in its visited order
similar def for col[i],dia[i]
*/