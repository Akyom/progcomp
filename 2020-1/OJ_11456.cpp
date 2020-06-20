#include <bits/stdc++.h>
//Diego Henríquez Valenzuela ID: 988567
using namespace std;
//Hecho por mi
int main(){
	int t;
	cin >> t;
	while(t){//test cases
		int n;
		cin >> n;
		int weight[n];
		for(int i=0;i<n;++i)cin >> weight[i];//lee entrada
		int lis[n],lds[n];
		int lt=0;//largest train
		for(int i=n-1; i>=0; --i){//i recorre el arreglo desde la ultima posición hasta la primera. i es el centro del tren.
			int maxlis=0, maxlds=0;
			for(int j=i+1; j<n; ++j){//buscamos la subsecuencia creciente y decreciente mas larga que tenga a i como primer elemento (o último si se ve al revéz)
				if(weight[j]<weight[i]){//por cada elemento en una posición mayor a i, si es que su peso es menor y su subsecuencia decreciente mas larga es mayor a maxlds
					if(lds[j]>maxlds)maxlds=lds[j];//actualizamos maxlds
				}
				else if(lis[j]>maxlis)maxlis=lis[j];//si es que el peso es mayor y su subsecuencia creciente mas larga es mayor a maxlis, actualizamos maxlis
			}
			lis[i]=maxlis+1;//guardamos los valores de lis y lds en la posición i
			lds[i]=maxlds+1;
			if(lt<lis[i]+lds[i]-1)lt=lis[i]+lds[i]-1;//sumamos ambas para obtener el largo del tren mas largo que tiene el centro en la posición i. Si el largo de este tren es mayor a lt, se guarda en lt
		}
		cout << lt << "\n";
		--t;
	}
	return 0;
}