#include<bits/stdc++.h>
using namespace std;
int main(){
    int len,s,i;
    string small,big;
    scanf("%d%d",&len,&s);

    if(len==1 && s==0){ //special case
        small=big="0";
    }else if(s<1 || s>9*len){
        small=big="-1";
    }else{
        //first deal with big,then we get small by reversing big
        while(s!=0){
            int num=min(s,9);
            big.push_back(num+'0');
            s-=num;
        }
        while(big.size()!=len){ //remember to fill in some 0 before reaching the length
            big.push_back('0');
        }

        for(i=big.size()-1;i>=0;i--){
            small.push_back(big[i]);
        }
        //find the first non zero and move to [0]
        if(small[0]=='0'){
            int idx=small.find_first_not_of('0');
            small[idx]-=1;
            small[0]='1';
        }
    }
    cout<<small<<" "<<big<<'\n';
    return 0;
}