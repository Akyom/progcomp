#include <stdio.h>

void funcion(int k,int n,int m){
	int x[k],y[k],i;
	for(i=0;i<k;++i){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(i=0;i<k;++i){
		if((x[i]==n)||(y[i]==m)){
			printf("divisa\n");
		}
		else{
			if(x[i]<n){
				if(y[i]<m) printf("SO\n");
				else printf("NO\n");
			}
			else{
				if(y[i]<m) printf("SE\n");
				else printf ("NE\n");
			}
		}	
	}
}	

int main(){
	int k,n,m;
	scanf("%d",&k);
	while(k!=0){
		scanf("%d%d",&n,&m);
		funcion(k,n,m);
		scanf("%d",&k);
	}
	return 0;	
}