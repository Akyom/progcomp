#include <stdio.h>

int dmin(int min,int tc,int coor[],int f){
	int mp=1,c=2,i;
	while(c<=tc){
		int d,sd=0;
		for(i=0;i<f;++i){
			d=((c-coor[i])>0)?c-coor[i]:coor[i]-c;
			sd+=d;
		}
		if(min>sd){
			min=sd;
			mp=c;
		}
		++c;
	}
	return mp;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t){
		int s,a,f;
		scanf("%d%d%d",&s,&a,&f);
		int scoor[f],acoor[f],i,smin=0,amin=0;
		for(i=0;i<f;++i){
			scanf("%d",&scoor[i]);
			scanf("%d",&acoor[i]);
			smin+=(scoor[i]-1);
			amin+=(acoor[i]-1);
		}
		int mps=dmin(smin,s,scoor,f);
		int mpa=dmin(amin,a,acoor,f);
		printf("(Street: %d, Avenue: %d)\n",mps,mpa);
		--t;
	}
	return 0;
}