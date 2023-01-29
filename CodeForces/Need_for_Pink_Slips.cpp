#include<bits/stdc++.h>
using namespace std;
void dfs(long double c,long double m,long double p,long double prob,int cnt,int depth);
long double ans,v;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans=(long double)0.0;
        long double c,m,p;
        //scanf("%llf%llf%llf%llf",&c,&m,&p,&v);
        cin>>c>>m>>p>>v;
        dfs(c,m,p,(long double)1.0,3,1);
        //printf("%.12f\n",ans);
        cout<<setprecision(12)<<fixed<<ans<<"\n";
    }
    return 0;
}
void dfs(long double c,long double m,long double p,long double prob,int cnt,int depth){
    ans+=(long double)depth*prob*p;
    //printf("(c,m,p)=(%f,%f,%f)\nprob=%.12f\ncnt=%d\ndepth=%d\n-----\n",c,m,p,prob,cnt,depth);
    //printf("depth*prob*p=%d*%f*%f=%f\nans=%f\n=======\n",depth,prob,p,1.0*depth*prob*p,ans);
    long double tmpc,tmpm,tmpp,delta;
    if(c > 1e-12){
        tmpc=max( 0.0l , c-v );
        if(tmpc>1e-12){
            delta=v/(long double)(cnt-1);
        }else{
            delta=c/(long double)(cnt-1);
        }
        if(m > 1e-12){
            tmpm=m+delta;
        }else{
            tmpm=m;
        }
        tmpp=p+delta;
        if(tmpc < 1e-12){
            dfs(tmpc,tmpm,tmpp,prob*c,cnt-1,depth+1);
        }else{
            dfs(tmpc,tmpm,tmpp,prob*c,cnt,depth+1);
        }
        
    }
    if(m > 1e-12){
        tmpm=max( 0.0l , m-v );
        if(tmpm>1e-12){
            delta=v/(long double)(cnt-1);
        }else{
            delta=m/(long double)(cnt-1);
        }
        if(c > 1e-12){
            tmpc=c+delta;
        }else{
            tmpc=c;
        }
        tmpp=p+delta;
        if(tmpm<1e-12){
            dfs(tmpc,tmpm,tmpp,prob*m,cnt-1,depth+1);
        }else{
            dfs(tmpc,tmpm,tmpp,prob*m,cnt,depth+1);
        }
    }
}