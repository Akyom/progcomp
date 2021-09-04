//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	while(cin >> n){//test cases
		int t;
		cin >> t;
		int tracks[t];
		for(int i=0; i<t; ++i)cin >> tracks[i];//lee entrada
		int combinacion=0, sumafinal=0;
		for(int i=0; i<pow(2,t);++i){//los bits de i representan las combinaciones
			int suma=0;
			bool q=true;
			for(int j=1; j<pow(2,t); j*=2){//j es una mascara para recorrer los bits de i uno a uno
				if(i&j)suma+=tracks[(int)log2(j)];//si el bit de i que estamos revisando con j está encendido, agregamos a suma el valor en la posición correspondiente de tracks
				if(suma>n){
					q=false;
					break;
				}	
			}	
			if(q && sumafinal<suma){//guardamos la combinacion con mayor suma que no exceda n
				sumafinal=suma;
				combinacion=i;
			}
		}
		for(int j=1; j<pow(2,t); j*=2)if(combinacion&j)cout << tracks[(int)log2(j)] << " ";//Imprime resultado
		cout << "sum:" << sumafinal << "\n";
	}
}