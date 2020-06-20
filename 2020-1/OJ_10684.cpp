#include <bits/stdc++.h>
//Diego Henríquez Valenzuela ID: 988567
using namespace std;
//Hecho por mi
int main(){
	int n;
	cin >> n;
	while(n){//test cases
		int aux, suma[n];
		cin >> suma[0];
		for(int i=1; i<n ; ++i){
			cin >> aux;//se lee el siguiente elemento en aux
			if(suma[i-1]>0)suma[i]=suma[i-1]+aux;//si la suma anterior es positiva entonces siempre conviene sumarla
			else suma[i]=aux;//si la suma anterior es negativa, solo se guarda el valor leído
		}
		int mayor=-10000000;
		for (int i=0; i<n; ++i){
			if(mayor<suma[i])mayor=suma[i];	//la suma mayor es la maxima ganancia que se puede obtener de apuestas consecutivas 
		}
		if(mayor<=0)cout << "Losing streak.\n";
		else cout << "The maximum winning streak is " << mayor << ".\n";
		cin >> n;
	}	
	return 0;
}