#include <stdio.h>

int main(){
	int t,k=1;
	scanf("%d",&t);
	while(k<=t){
		int n,i;
		scanf("%d",&n);
		getchar();
		char v[n];
		for(i=0;i<n;++i){
  			scanf("%c",&v[i]);
  		}
  		int s=0;
  		for(i=0;i<n;++i){
  			if(v[i]==46){
  				++s;
  				i+=2;
  			}
  		}
  		printf("Case %d: %d\n",k,s);
		++k;
	}
	return 0;
}
