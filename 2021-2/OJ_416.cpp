//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez
#include <iostream>

using namespace std;

string numeros[10] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY","YYYYNYY"}; //arreglo con las correctas representaciones de los números

bool corresponde(string a, string b, bool* burned){
	bool c=true;
	for(int i=0; i<7; ++i){//marca las LEDs quemadas
		if(a[i]=='Y' && b[i]=='N'){
			burned[i]=true;
		}
		else if((a[i]=='N' || burned[i])&& b[i]=='Y'){//Si una LED que se asumía quemada está prendida o si una led que no debería estar prendida lo está, el número no corresponde
			c=false;
			break;
		}
	}
	return c;
}

int main() {
	int n;
	cin >> n;
	while(n){//test cases
		string secuencia[n];
		for(int i=0; i<n; ++i){//lee entrada
			cin >> secuencia[i];
		}
		bool match = false;
		for(int i=9; i>=n-1; --i){
			bool burned[7]={false, false, false, false, false, false, false};
			if(corresponde(numeros[i], secuencia[0], burned)){//si el primer número corresponde comparar desde ese
				bool matchahora = true;
				for(int j=1; j<n; ++j){
					if(!corresponde(numeros[i-j], secuencia[j], burned)){//si un número corresponde, este no es el match
						matchahora = false;
						break;
					}
				}
				if(matchahora){//si este fue el match, hay match
					match=true;
					break;
				}
			}
		}
		if(match)cout << "MATCH\n";
		else cout << "MISMATCH\n";
		cin >> n;
	}
}