#include<bits/stdc++.h>
using namespace std;
unordered_set<int> us;
vector<int> ans;
bool can_be_ans[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        us.emplace(num);
    }

    //every num can be ans initially
    for(int i=1;i<=100000;i++){
        can_be_ans[i]=true;
    }

    ans.emplace_back(1);
    for(int i=2;i<=m;i++){
        if(!can_be_ans[i]){
            continue;
        }
        bool isans=true;
        for(int j=i;j<=100000;j+=i){
            if(us.find(j)!=us.end()){   //there exists a num j in a[] s.t. gcd(i,j) != 1
                isans=false;
                break;
            }
        }
        if(isans){  //every num in a[] satisfy gcd(num,i) == 1
            ans.emplace_back(i);
        }else{
            for(int j=i;j<=100000;j+=i){    //if i can't be the ans, then neither 2i,3i,... can be the final ans
                can_be_ans[j]=false;
            }
        }
    }

    printf("%ld\n",ans.size());
    for(auto num:ans){
        printf("%d\n",num);
    }
    return 0;
}
/*
eratosthenes
can_be_ans[i] = true if i can be the final ans
*/