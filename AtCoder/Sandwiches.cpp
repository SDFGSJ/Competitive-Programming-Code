#include<bits/stdc++.h>
using namespace std;
int a[300010];
map<int,vector<int>> pos;   //<num,list of idx>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        pos[a[i]].emplace_back(i);
    }

    long long ans=0;
    for(auto [k,vec]:pos){
        for(int i=0;i<vec.size()-1;i++){
            int cnt=vec[i+1]-vec[i]-1;  //cnt is # of elements between index (vec[i], vec[i+1])
            ans+=1ll*cnt*(i+1)*(vec.size()-i-1);    //i+1 is the # of k in [0, vec[i]], vec.size()-i-1 is the # of k in [vec[i+1], n-1]
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
similar to 375d
pos[i] = a list of indexes of number i appeared in a[]

ex. a[] = {9 7 11 7 3 8 1 13 11 11 11 6 13}
[1]:6
[3]:4
[6]:11
[7]:1,3
[8]:5
[9]:0
[11]:2,8,9,10
[13]:7,12

take [11]:2,8,9,10 as example
2,8 => there are 8-2-1 = 5 numbers between idx 2 and 8
there is 1 11 on the LHS (in [0,2]), and 3 11's on the RHS (in [8,12]) of these 5 numbers
so these 5 numbers contribute 5*1*3 to final ans

8,9 => there are 9-8-1 = 0 number between idx 8 and 9
there are 2 11's on the LHS (in [0,8]), and 2 11's on the RHS (in [9,12]) of these 0 number
so these 0 number contribute 0*2*2 to final ans

9,10 => there are 10-9-1 = 0 number between idx 9 and 10
there are 3 11's on the LHS (in [0,9]), and 1 11's on the RHS (in [10,12]) of these 0 numbers
so these 0 number contribute 0*3*1 to final ans
*/