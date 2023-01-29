#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n,l,i;
    double Max=-1.0;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=0;i+1<n;i++){
        if(Max<a[i+1]-a[i]){
            Max=a[i+1]-a[i];
        }
    }
    Max=max({Max/2.0, (double)a[0], (double)(l-a[n-1]) });
    printf("%.10f\n",Max);
    return 0;
}