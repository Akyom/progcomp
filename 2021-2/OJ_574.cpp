//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int t,n;
	cin >> t >> n;
	while(n){//test cases
		cout << "Sums of " << t << ":\n";
		int numeros[n];
		for(int i=0; i<n; ++i)cin >> numeros[i];//lee entrada
		vector<vector<int> > resultados;
		for(int i=pow(2,n)-1; i>=0; --i){//los bits de i representan las combinaciones. Vamos en orden decreciente porque así pide el output el enunciado.
			int suma=0;
			for(int j=1; j<pow(2,n); j*=2){//j es una mascara para recorrer los bits de i uno a uno
				if(i&j)suma+=numeros[((int)log2(j)-n+1>0)?(int)log2(j)-n+1:((int)log2(j)-n+1)*-1];//si el bit de i que estamos revisando con j está encendido, agregamos a suma el valor en la posición correspondiente de numeros. Le restamos n-1 y sacamos el valor absoluto debido al orden pedido en el enunciado.
				if(suma>t)break;
			}	
			if(suma==t){
				vector<int> v;
				for(int j=pow(2,n-1); j>0; j/=2)if(i&j)v.push_back(numeros[((int)log2(j)-n+1>0)?(int)log2(j)-n+1:((int)log2(j)-n+1)*-1]);//guarda la combinacion en v
				bool norepetido=true;
				for(int j=0; j<resultados.size(); ++j){//busca si la combinacion ya fue guardada en resultados
					if(resultados[j].size()==v.size()){
						bool igual=true;
						for(int k=0; k<v.size(); ++k){
							if(resultados[j][k]!=v[k]){
								igual=false;
								break;
							}
						}
						if(igual){
							norepetido=false;
							break;
						}
					}
				}
				if(norepetido)resultados.push_back(v);//si la combinacion no estaba guardada ya en resultado, la guarda
			}	
		}
		if(resultados.empty())cout << "NONE\n";//imprime
		else for(int i=0; i<resultados.size(); ++i){
			for(int j=0; j<resultados[i].size(); ++j){
				if(!j)cout << resultados[i][j];
				else cout << "+" << resultados[i][j];
			}
			cout << "\n";
		}		
		cin >> t >> n;
	}
}