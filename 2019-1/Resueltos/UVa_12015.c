#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		printf("Case #%d:\n",i);
		char string[10][101];
		int v[10],mayor=0;
		for(int j=0;j<10;++j){
			scanf("%s",string[j]);
			scanf("%d",&v[j]);
			if(mayor<v[j])mayor=v[j];
		}
		for(int j=0;j<10;++j){
			if(mayor==v[j]){
				for(int k=0;string[j][k]!='\0';++k){
					printf("%c",string[j][k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}