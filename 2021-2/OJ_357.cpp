//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez
//Online Judge Username: Akyom ID: 988567

#include <iostream>

using namespace std;

int main() {
  	int coins[5] = {1,5,10,25,50};
	long long change[30001] = {0};
	change[0]=1;
	for(int i=0; i<5; ++i){
		for(int j=coins[i]; j<30001; ++j){
			change[j]+=change[j-coins[i]];//Simula poner una nueva moneda del tipo con mayor valor hasta ahora y suma las combinaciones posibles para llegar al valor
		}
	}
	//for(int i=0; i<30001; ++i)cout << i << ": "<< change[i] << "\n";
	int n;
	while(cin >> n){//lee entrada
		if(change[n]==1)cout << "There is only 1 way to produce " << n << " cents change.\n";
		else cout << "There are " << change[n] << " ways to produce " << n << " cents change.\n";
	}
} 