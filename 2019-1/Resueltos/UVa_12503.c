#include <stdio.h>
#include <string.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t){
		int n,pos=0;
		scanf("%d",&n);
		int v[n],aux;
		char ins[6];
		for(int i=0;i<n;++i){
			scanf("%s",ins);
			if(!strcmp(ins,"LEFT"))v[i]=-1;
			if(!strcmp(ins,"RIGHT"))v[i]=1;
			if(!strcmp(ins,"SAME")){
				scanf("%s",ins);
				scanf("%d",&aux);
				v[i]=v[aux-1];
			}
			pos+=v[i];
		}
		printf("%d\n",pos);
		--t;
	}
	return 0;
}