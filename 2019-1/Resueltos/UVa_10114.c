#include <stdio.h>

int main(){
	int months;
	scanf("%d",&months);
	while(months>=0){
		float dp,debt,d,pay; int ndr,nm,i;
		scanf("%f%f%d%d",&dp,&debt,&ndr,&nm);
		float car=dp+debt;
		pay=debt/months;
		for(i=0;i<months;++i){
			if(i==nm){
				scanf("%f",&d);
				--ndr;
				if(ndr>0)scanf("%d",&nm);
			}
			if(i)debt=debt-pay;
			car=car-(car*d);
			if(car>debt){
				while(ndr){
					scanf("%f",&d);
					--ndr;
					if(ndr>0)scanf("%d",&nm);
				}
				break;
			}
			//printf("%d debt:%f car:%f\n",i,debt,car);
		}
		if(i!=1)printf("%d months\n",i);
		else printf("%d month\n",i);
		scanf("%d",&months);
	}
}