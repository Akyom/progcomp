#include <stdio.h>

void funcion(int n){
	int i,j,k,l,m[n][5],q,cont,s=1,u=1;
	for(i=0;i<n;++i){
		for(j=0;j<5;++j){
			scanf("%d",&m[i][j]);
		}
	}
	for(i=0;i<n-1;++i){
		cont=1;
		for(j=i+1;j<n;++j){
			for(k=0;k<5;++k){
				q=0;
				for(l=0;l<5;++l){
					if(m[i][k]==m[j][l]){
						q=1;
						break;
					}
				}
				if(q==0){
					break;
				}
			}
			if(q==1){
				++cont;
			}
		}
		if(s==cont){
			++u;
		}
		if(s<cont){
			s=cont;
			u=1;
		}
	}
	printf("%d\n",s*u);
}

int main(){
	int n;
	scanf("%d",&n);
	while(n!=0){
		funcion(n);
		scanf("%d",&n);
	}
	return 0;
}