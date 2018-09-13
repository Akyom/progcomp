#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	long long v[400000];
	long long n;
	int i;
	double d;
	for(i=0;scanf("%lli",&n)!=EOF;++i){
		v[i]=n;
	}
	--i;
	while(i>=0){
		d=sqrtl(v[i]);
		printf("%.4lf\n",d);
		--i;
	}
	return 0;
}