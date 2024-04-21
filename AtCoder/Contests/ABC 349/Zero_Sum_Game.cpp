#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n-1;i++){
        int num;
        scanf("%d",&num);
        sum+=num;
    }
    printf("%d\n",-sum);
    return 0;
}