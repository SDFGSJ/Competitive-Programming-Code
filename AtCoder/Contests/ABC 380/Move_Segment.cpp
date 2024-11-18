#include<bits/stdc++.h>
using namespace std;
char s[500010];
vector<pair<int,int>> seg;
int main(){
    int n,k;
    scanf("%d%d%s",&n,&k,s);
    k--;

    for(int i=0;i<n;){
        if(s[i]=='1'){
            int j=i;
            while(j<n && s[j]=='1'){
                j++;
            }
            j--;
            seg.emplace_back(i,j);
            i=j+1;
        }else{
            i++;
        }
    }

    int l=seg[k-1].second+1, r=l+(seg[k].second-seg[k].first+1)-1;
    for(int i=l,j=seg[k].first;i<=r;i++,j++){
        swap(s[i],s[j]);
    }
    printf("%s\n",s);
    return 0;
}
/*
swap the chars [l,r] after (k-1)th segment with kth segment [seg[i].f, seg[i].s]
*/