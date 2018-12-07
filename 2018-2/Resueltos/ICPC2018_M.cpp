#include <stdio.h>

int main(){
	int n,p=0,q;
	scanf("%d",&n);
	int r=n;
	for(int i=0;i<n;++i){
		scanf("%d",&q);
		if(q<=p)--r;
		p=q;
	}
	printf("%d",r);
	return 0;
}