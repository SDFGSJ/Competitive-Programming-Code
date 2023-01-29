#include<stdio.h>
#include<string.h>
char str[105];
int q[105];
int a[105];
int main(void)
{
	int i,j,k,q_idx=0,a_idx=0,cnt=0;
	
	scanf("%s",str);
	int len=strlen(str);
	
	for(i=0;i<len;i++){
		if(str[i]=='Q'){
			q[q_idx]=i;
			q_idx++;
		}else if(str[i]=='A'){
			a[a_idx]=i;
			a_idx++;
		}
	}
	
	for(i=0;i<a_idx;i++){
		for(j=0;j<q_idx;j++){
			for(k=j+1;k<q_idx;k++){
				if(q[j]<a[i] && a[i]<q[k]){
					cnt++;
				}
			}
		}
	}
	printf("%d\n",cnt);
	/*printf("q[]=");
	for(i=0;i<q_idx;i++){
		printf("%d,",q[i]);
	}
	printf("\na[]=");
	for(i=0;i<a_idx;i++){
		printf("%d,",a[i]);
	}*/
	return 0;
}
