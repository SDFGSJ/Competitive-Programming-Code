#include<bits/stdc++.h>
using namespace std;
char s[200010];
int distri[10];
vector<vector<int>> multi_of_8;
void check_and_push(int num){
    int hund=num/100, ten=(num/10)%10, one=num%10;
    vector<int> vec(10,0);
    vec[hund]++,vec[ten]++,vec[one]++;
    multi_of_8.emplace_back(vec);
}
void get_8_distri(){
    for(int num=104;num<1000;num+=8){
        check_and_push(num);
    }
}
bool special_case(int len){
    if(len==1){
        return s[0]=='8';
    }

    int num1=(s[0]-'0')*10+(s[1]-'0'), num2=(s[1]-'0')*10+(s[0]-'0');
    return num1%8==0 || num2%8==0;
}
int main(){
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        distri[s[i]-'0']++;
    }

    bool is_multi_of_8=false;
    if(len<=2){
        is_multi_of_8=special_case(len);
    }else{
        get_8_distri();
        for(auto vec:multi_of_8){
            bool ok=true;
            for(int i=0;i<=9;i++){
                if(vec[i]>distri[i]){
                    ok=false;
                }
            }
            if(ok){
                is_multi_of_8=true;
            }
        }
    }

    if(is_multi_of_8){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
multiple of 8
only the rightmost 3 digits matters
if |S|<=2, treat it as special case

if |S|>=3, get the digit distribution of the multiple of 8 that >= 100
then check whether each distribution can be satisfied using the distribution of S
*/