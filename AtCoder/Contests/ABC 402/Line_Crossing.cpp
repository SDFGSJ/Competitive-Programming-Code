#include<bits/stdc++.h>
using namespace std;
int seg[1000010];   //seg[i] = # of line parallel to line (0,i)
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    long long ans=0;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;    //0-indexed
        int mod=(a+b)%n;    //line (a,b) is parallel to (0,mod)
        ans+=(i-1)-seg[mod];
        seg[mod]++;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
tricky idea
we convert any line (a,b) into the form of (0,i) where 1<=i<=n-1
given a line (a,b), we want to know which i makes (a,b) and (0,i) become parallel
=> i would be (a+b)%n, since line (a,b) cuts (b-a) chords on circumference
if (0,i) wants to become parallel with (a,b), then we need (a-0)+(b-a)+(a-0) = a+b chords
(we observe this by shifting line (a,b) on the circle)
but a+b might >= n, so we need to take the mod of it

to calc ans, we add lines 1 by 1 and find the # of lines that are parallel to the line we are adding now
=> we have add (i-1) edges until now, and the # of line parallel to the current line is seg[mod]

Note.
seg[0] = # of lines that is not parallel to any (0,i) lines
ex. (1,n-1) (0-indexed)
*/