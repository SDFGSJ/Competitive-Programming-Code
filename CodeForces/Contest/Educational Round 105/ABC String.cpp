#include<stdio.h>
#include<string.h>
char str[55];
int main(void)
{
	int t,i,j;
	int cnt,yes;
	scanf("%d",&t);
	while(t--){
		yes=cnt=0;
		scanf("%s",str);
		int len=strlen(str);
		if(str[0]==str[len-1]){	//�p�G�Y�����O�@�˪��r�A"()"���藍�i��match 
			printf("NO\n");
			continue;
		}
		for(i=0;i<2;i++){	//�a�|�⦸ 
			int cnt=0;
			for(j=0;j<len;j++){
				if(str[j]==str[0]){	//'('
					cnt++;
				}else if(str[j]==str[len-1]){	//')'
					cnt--;		
				}else{
					if(i==0)
						cnt++;	//'('
					else
						cnt--;	//')'
				}
				if(cnt<0){	//cnt<0�N��')'�Ӧh�A�������i�� exception:ACCBBC
					yes=0;
					break;
				}
			}
			if(cnt==0){
				yes=1;
				printf("YES\n");
				break;
			}
		}
		if(!yes){
			printf("NO\n");
		}
	}
	return 0;
}
