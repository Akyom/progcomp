#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	printf("Lumberjacks:\n");
	while(n){
		int a,b,p=0,q=1,m=9;
		scanf("%d",&a);
		while(m){
			scanf("%d",&b);
			if(m!=9){
				if(((p==1)&&(a>b))||((!p)&&(a<b))){
					q=0;
					p=2;
				}	
			}	
			if((m==9)&&(a<b))p=1;
			a=b;
			--m;
		}
		if(q)printf("Ordered\n");
		else printf("Unordered\n");
		--n;
	}
	return 0;
}