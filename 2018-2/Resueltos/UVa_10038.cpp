#include <stdio.h>

int main(){
	int v[3000],i,n,a,b,r,p;
	while(scanf("%d",&n)!=EOF){
		p=1;
		for(i=0;i<3000;++i){
			v[i]=0;
		}
		scanf("%d",&a);
		for(i=0;i<n-1;++i){
			scanf("%d",&b);
			r=((a-b)>0)?a-b:b-a;
			if(r<n)v[r]=1;	
			a=b;
		}
		for(i=1;i<n;++i){
			if(!v[i]){
				p=0;
				break;
			}
		}
		if(p)printf("Jolly\n");
		else printf("Not jolly\n");
	}

	return 0;
}