#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n,i,j,pila1,pila2,diferencia,resultado;
	scanf("%d",&n);
	int v[n];
	for(i=0;i<n;++i){
		scanf("%d",&v[i]);
	}
	for(i=0;i<pow(2,n);++i){
		pila1=0;
		pila2=0;
		for(j=0;j<n;++j){
			if(i&(int)pow(2,j))pila1+=v[j];
			else pila2+=v[j];
		}
		diferencia=((pila1-pila2)>0)?(pila1-pila2):(pila2-pila1);
		if((resultado>diferencia)||(!i))resultado=diferencia;
		if(!resultado)break;
	}
	printf("%d",resultado);
}