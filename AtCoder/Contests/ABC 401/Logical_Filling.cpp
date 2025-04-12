#include<bits/stdc++.h>
using namespace std;
char s[200010];
vector<pair<int,int>> odd; //<start idx,len of '?...?' string>
int main(){
    int n,k;
    scanf("%d%d%s",&n,&k,s);
    int qcnt=0,ocnt=0;  //qcnt = # of '?', ocnt = # of 'o'
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            qcnt++;
        }else if(s[i]=='o'){
            ocnt++;
        }
    }

    for(int i=0;i<n;i++){
        if(s[i]=='o'){  //if s[i] is 'o', then s[i-1] and s[i+1] must be '.'
            if(i-1>=0 && s[i-1]=='?'){
                s[i-1]='.';
                qcnt--;
            }
            if(i+1<=n-1 && s[i+1]=='?'){
                s[i+1]='.';
                qcnt--;
            }
        }
    }

    int max_cap=0;  //max # of 'o' we can get by replacing the remaining '?' in s[]
    for(int i=0;i<n;){
        if(s[i]=='?'){  //calc the run length encoding of '?...?' string
            int cnt=0,idx=i;
            while(s[idx]=='?'){
                cnt++,idx++;
            }
            if(cnt%2){  //'?...?' string with odd length
                odd.emplace_back(idx-cnt,cnt);
            }
            max_cap+=(cnt+1)/2; //the max # of 'o' we can get in k? string = ceil(cnt/2)
            i=idx;
        }else{
            i++;
        }
    }

    int remain_ocnt=k-ocnt; //# of remaining 'o' we need to put in order to have k 'o's
    if(remain_ocnt==0){ //replace all '?' with '.'
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                s[i]='.';
            }
        }
    }else if(remain_ocnt==max_cap){ //there's only 1 way to fill in 'o' in odd-length k? string (even-length k? string has 2 ways to fill in 'o')
        for(auto [idx,cnt]:odd){
            for(int i=idx;i<idx+cnt;i++){
                if((i%2)==(idx%2)){
                    s[i]='o';
                }else{
                    s[i]='.';
                }
            }
        }
    }
    printf("%s\n",s);
    return 0;
}
/*
divide by case and solve carefully
we denote '??...?' (k question marks) to be "k?" string
for all even-length k? string, we have 2 ways to replace '?' with 'o' in order to maximize the # of 'o' we can put
ex. 4? = ???? => "o.o." or ".o.o"

for odd-length k? string, there's only 1 way to replace '?' with 'o' in order to maximize the # of 'o' we can put
ex. 5? = ????? => "o.o.o"

if (the # of remaining 'o' we need to put) < (max # of 'o' we can get by replacing '?')
then we know some k? string will not have max # of 'o'
which makes this k? string end up being '?...?' in final s[i]
ex. suppose we have 2?,3?,5? string and (the # of remaining 'o' we need to put) = 5
then we have following ways to put 'o':
o. | o.o | o...o (5? string does not have max # of 'o')
o. | o.. | o.o.o (3? ...)
.. | o.o | o.o.o (2? ...)
*/