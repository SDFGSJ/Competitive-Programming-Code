#include<bits/stdc++.h>
using namespace std;
struct subject{
    long long grade,essay;
    bool operator<(const subject& s){
        return essay<s.essay;
    }
};
subject a[100010];
int main(){
    long long n,maxscore,avg,total=0,cnt=0,i;

    scanf("%lld%lld%lld",&n,&maxscore,&avg);
    for(i=0;i<n;i++){
        scanf("%lld%lld",&a[i].grade,&a[i].essay);
        total+=a[i].grade;
    }

    sort(a,a+n);
    
    i=0;
    while(total<n*avg){
        cnt+=min(n*avg-total,maxscore-a[i].grade) * a[i].essay;
        total+=min(n*avg-total,maxscore-a[i].grade);
        i++;
    }
    printf("%lld\n",cnt);
    return 0;
}