#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int n;
long long calc(bool omote_ispos,bool ura_ispos){
    long long result=0;
    for(int i=0;i<n;i++){
        long long omote_sum=omote_ispos?a[i]:-a[i];
        long long ura_sum=ura_ispos?b[i]:-b[i];
        if(omote_sum+ura_sum>=0){
            result+=omote_sum+ura_sum;
        }
    }
    return result;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }

    printf("%lld\n",max({calc(0,0),calc(0,1),calc(1,0),calc(1,1)}));
    return 0;
}
/*
remove absolute value and consider all 4 cases(enumerate positive/negative signs)
*/