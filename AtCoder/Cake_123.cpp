#include<bits/stdc++.h>
using namespace std;
long long A[1005],B[1005],C[1005];
priority_queue<long long,vector<long long>,greater<long long>> pq;
vector<long long> ans;
int main(){
    int x,y,z,K;
    scanf("%d%d%d%d",&x,&y,&z,&K);
    for(int i=0;i<x;i++){
        scanf("%lld",&A[i]);
    }
    for(int i=0;i<y;i++){
        scanf("%lld",&B[i]);
    }
    for(int i=0;i<z;i++){
        scanf("%lld",&C[i]);
    }
    sort(A,A+x,greater<>());
    sort(B,B+y,greater<>());
    sort(C,C+z,greater<>());

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                if(pq.size()<K){
                    pq.emplace(A[i]+B[j]+C[k]);
                }else{
                    if(pq.top()<A[i]+B[j]+C[k]){   //smallest element in pq < current sum => replace it
                        pq.pop();
                        pq.emplace(A[i]+B[j]+C[k]);
                    }else{  //A[i]+B[j]+C[k] <= smallest element in pq, ans so does A[i]+B[j]+C[k+1], no need to try anymore
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<K;i++){
        ans.emplace_back(pq.top());
        pq.pop();
    }
    for(int i=ans.size()-1;i>=0;i--){
        printf("%lld\n",ans[i]);
    }
    return 0;
}
/*
smart enumerate + priority queue
sort A[],B[],C[] desc and brute force enumerate
*/