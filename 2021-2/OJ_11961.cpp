//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez
#include <iostream>
#include<vector>

using namespace std;

string ADN = {'A','C','G','T'};

void mutar(int n, int k, string secuencia, int m, int i, vector<string>* resultados){
	if(m==k || i==n){//fondo de la recursividad. Si es que m==k quiere decir que no se debe seguir mutando así que guarda y retorna. Si i==n ya completamos la secuencia así que guarda y retorna aunque m sea 0 o 1 (puesto que en realidad si hay 2 mutaciones pero reemplazan el caracter por el mismo caracter).
		resultados->push_back(secuencia);
		return;
	}
	bool muto = false;
	char aux = secuencia[i];
	for(int j=0; j<4; ++j){//Pone el valor de la posición i en secuencia por el caracter de la posición j en ADN
		if(secuencia[i]!=ADN[j]){//Si es que el caracter es diferente lo cambia
			secuencia[i]=ADN[j];
			muto = true;//Si lo cambió, se guarda para deshacer la mutacion despues
			++m;//Guarda la cantidad de mutaciones
		}
		mutar(n,k,secuencia,m,i+1,resultados);//LLama a mutar con la siguiente posición de i
		if(muto){//Si mutó, deshace la mutación
			secuencia[i]=aux;
			muto = false;
			--m;
		}
	}
	
}

int main() {
	int t;
	cin >> t;
	while(t--){//test cases
		int n,k;
		cin >> n >> k;
		string secuencia;
		char aux;
		for(int i=0; i<n; ++i){//lee entrada
			cin >> aux;
			secuencia+=aux;
		}
		vector<string> resultados;
		mutar(n,k,secuencia,0,0,&resultados);//funcion que guarda todas las k-mutaciones en el arreglo resultados
		cout << resultados.size() << "\n";
		for(int i=0; i<resultados.size(); ++i)cout << resultados[i] << "\n";
	}
}