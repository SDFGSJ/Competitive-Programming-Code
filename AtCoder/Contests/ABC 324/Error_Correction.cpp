#include<bits/stdc++.h>
using namespace std;
char str[500010];
char tp[500010];
vector<int> ans;
bool isPreorSuf(int tlen,int slen){
    int pre_diff=0,suf_diff=0;
    //prefix
    int len=min(tlen,slen);
    for(int i=0;i<len;i++){
        if(tp[i]!=str[i]){
            pre_diff++;
        }
    }

    //suffix
    for(int i=tlen-1,j=slen-1;i>=tlen-len && j>=slen-len;i--,j--){
        if(tp[i]!=str[j]){
            suf_diff++;
        }
    }
    //printf("pre diff=%d,suf diff=%d\n",pre_diff,suf_diff);
    return (!pre_diff || !suf_diff);
}
int main(){
    int n;
    scanf("%d%s",&n,tp);    //tp=T'
    int tlen=strlen(tp);
    for(int i=0;i<n;i++){
        bool isans=false;
        scanf("%s",str);
        int slen=strlen(str);

        if(slen==tlen){
            if(strcmp(tp,str)==0){
                isans=true;
            }else{
                int count=0;
                for(int j=0;j<slen;j++){
                    count+=(str[j]!=tp[j]);
                }
                //printf("count=%d\n",count);
                if(count==1){
                    isans=true;
                }
            }
        }else{
            if(slen==tlen+1){   //S = T' insert 1 char
                int count=0;
                for(int j=0,k=0;j<slen && k<tlen;j++,k++){
                    if(str[j]!=tp[k] && tp[k]==str[j+1]){
                        count++;
                        j++;
                    }else if(str[j]!=tp[k] && tp[k]!=str[j+1]){
                        count+=2;
                        j++;
                    }
                }

                //printf("count=%d\n",count);
                if(isPreorSuf(tlen,slen) || count==1){
                    isans=true;
                }
            }else if(slen==tlen-1){ //S = remove 1 char from T'
                int count=0;
                for(int j=0,k=0;j<slen && k<tlen;j++,k++){
                    if(str[j]!=tp[k] && str[j]==tp[k+1]){
                        count++;
                        k++;
                    }else if(str[j]!=tp[k] && str[j]!=tp[k+1]){
                        count+=2;
                        k++;
                    }
                }
                //printf("count=%d\n",count);
                if(isPreorSuf(tlen,slen) || count==1){
                    isans=true;
                }
            }
        }
        if(isans){
            ans.push_back(i+1);
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        if(i!=0){
            printf(" ");
        }
        printf("%d",ans[i]);
    }
    return 0;
}