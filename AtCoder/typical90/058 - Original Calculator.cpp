#include<bits/stdc++.h>
using namespace std;
unordered_set<long long> s; //check duplicate
vector<long long> v;    //num sequence
int digit_sum(long long num){
    int result=0;
    while(num>0){
        result+=(num%10);
        num/=10;
    }
    return result;
}
int main(){
    long long n,k;
    scanf("%lld%lld",&n,&k);
    long long num=n,dupli=-1;
    while(true){
        if(s.count(num)){   //find duplicate
            dupli=num;
            break;
        }
        s.emplace(num);
        v.emplace_back(num);
        num+=digit_sum(num);
        if(num>=100000){
            num-=100000;
        }
    }

    int cnt=0;  //find #steps from n to duplicate number
    num=n;
    while(num!=dupli){
        num+=digit_sum(num);
        if(num>=100000){
            num-=100000;
        }
        cnt++;
    }

    if(k<=cnt){
        printf("%lld\n",v[k]);
    }else{
        k-=cnt;
        printf("%lld\n",v[cnt+(k%(v.size()-cnt))]);
    }
    return 0;
}
/*
1->2->5->10->15->5
beware of non-loop part
*/