/*#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[200010];
int sufmin[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);

    sufmin[n-1]=a[n-1].second;
    for(int i=n-1;i>=0;i--){
        sufmin[i-1]=min(sufmin[i],a[i-1].second);
    }

    long long ans=0;
    for(int i=1;i<=m;i++){
        int idx=lower_bound(a,a+n,make_pair(i,0))-a;
        if(idx==n){
            ans+=m-i+1;
        }else{
            ans+=sufmin[idx]-i;
        }
    }
    printf("%lld\n",ans);
    return 0;
}*/

/*
method 2
suffix min + focus on L and find desired R
maxR[i] = the rightmost r of a segment starting at l that does not overlap with any segment

ex. given [1,5], in order not to overlap with [1,5],
the rightmost r that 1 can reach is 5-1=4
if r reach 5, it will overlap with itself
*/
#include<bits/stdc++.h>
using namespace std;
int maxR[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    //init
    for(int i=1;i<=m;i++){
        maxR[i]=m;
    }

    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        maxR[l]=min(maxR[l],r-1);   //might have multiple segments that start at the same l
    }

    //suffix min of maxR[1..m]
    for(int i=m-1;i>=1;i--){
        maxR[i]=min(maxR[i],maxR[i+1]);
    }

    long long ans=0;
    for(int l=1;l<=m;l++){
        ans+=maxR[l]-l+1;
    }
    printf("%lld\n",ans);
    return 0;
}

/*
method 3
prefix max + focus on R and find desired L
minL[i] = the leftmost l of a segment ending at r that does not overlap with any segment

ex. given [1,5], in order not to overlap with [1,5],
the leftmost l that 5 can reach is 1+1=2
if l reach 1, it will overlap with itself
*/
/*#include<bits/stdc++.h>
using namespace std;
int minL[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    //init
    for(int i=1;i<=m;i++){
        minL[i]=1;
    }

    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        minL[r]=max(minL[r],l+1);   //might have multiple segments that end at the same r
    }

    //prefix max of minL[1..m]
    for(int i=1;i<=m;i++){
        minL[i]=max(minL[i],minL[i-1]);
    }

    long long ans=0;
    for(int r=1;r<=m;r++){
        ans+=r-minL[r]+1;
    }
    printf("%lld\n",ans);
    return 0;
}*/