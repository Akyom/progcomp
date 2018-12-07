#include <stdio.h>
#include <math.h>

int bt(int l,int b[],int nb){
	for(int i=0;i<pow(2,nb);++i){
		int a=1,suma=0;
		for(int j=0;j<nb;++j,a=a<<1){
			if(a&i)suma+=b[j];
			if(suma>=l)break;
		}
		if(suma==l)return 1;
	}
	return 0;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t){
		int n,p,r;
		scanf("%d%d",&n,&p);
		int v[p];
		for(int i=0;i<p;++i){
			scanf("%d",&v[i]);
		}
		r=bt(n,v,p);
		if(r)printf("YES\n");
		else printf("NO\n");
		--t;
	}	
	return 0;
}	