#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool isprime[1000010];
unordered_map<int,int> m;   //<value,cnt>
int main(){
    int n;
    scanf("%d",&n);

    int M=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        M=max(M,a[i]);
        m[a[i]]++;
    }

    //sort a[] in ascending order so that we can fill the bool array from smallest elements
    sort(a,a+n);

    for(int i=1;i<=M;i++){
        isprime[i]=true;
    }

    int ans=0;
    for(int i=0;i<n;i++){
        if(isprime[a[i]]){
            if(m[a[i]]<2){  //dont count the duplicate element
                ans++;
            }
            for(int j=a[i];j<=M;j+=a[i]){
                isprime[j]=false;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
eratosthenes
add 1 to ans only when the number is first met and is not duplicate
*/