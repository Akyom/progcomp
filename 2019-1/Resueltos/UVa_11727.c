#include <stdio.h>

int main(){
	int t,c=1;
	scanf("%d",&t);
	while(t>0){
		int x,y,z,r;
		scanf("%d%d%d",&x,&y,&z);
		if(x>y){
			if(z>x)r=x;
			else{	
				if(y>z)r=y;
				else r=z;
			}	
		}	
		else{
			if(x>z)r=x;
			else{
				if(y>z)r=z;
				else r=y;
			}
		}
		printf("Case %d: %d\n",c,r);
		++c;
		--t;
	}
}