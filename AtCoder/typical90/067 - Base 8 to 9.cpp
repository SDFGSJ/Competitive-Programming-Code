#include<bits/stdc++.h>
using namespace std;
string oct_to_nine(long long oct){
    deque<int> result;
    while(oct){
        result.emplace_front(oct%9);
        oct/=9;
    }
    string nine;
    for(auto i:result){
        nine.push_back('0'+i);
    }
    return nine;
}
long long eight_to_five(string& nine){
    string oct=nine;
    for(int i=0;i<oct.length();i++){
        if(oct[i]=='8'){
            oct[i]='5';
        }
    }
    return stoll(oct,0,8);
}
int main(){
    long long oct;
    int k;
    scanf("%llo%d",&oct,&k);

    if(oct==0){
        printf("0\n");
        return 0;
    }

    string nine;
    while(k--){
        nine=oct_to_nine(oct);
        oct=eight_to_five(nine);
    }
    printf("%llo\n",oct);
    return 0;
}