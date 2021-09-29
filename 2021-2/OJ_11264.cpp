//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez

#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){//test cases
		int n;
		cin >> n;
		int coins[n];
		for(int i=0; i<n; ++i)cin >> coins[i];//lee entrada
		int nmonedas = 0, valor = 0;
		for(int i=0; i<n-1; ++i){
			if(coins[i]+valor<coins[i+1]){//por cada moneda ve si la podemos sacar sin que salga la siguiente en vez
				valor += coins[i];//aumenta el valor que sacamos
				++nmonedas;//sacamos una moneda mas
			}	
		}
		cout << ++nmonedas << "\n";//siempre sacamos la ultima, imprime resultado

	}
}	