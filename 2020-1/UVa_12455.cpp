#include <bits/stdc++.h>
//Diego Henríquez
using namespace std;
//Hecho por mi
int main(){
	int t;
	cin >> t;
	while(t){ //test cases
		int n,p;
		bool q=true;
		cin >> n >> p; //lee entrada
		int bars[p];
		for(int i=0; i<p; ++i)cin >> bars[i];
		for(int i=0; i<pow(2,p); ++i){ //i pasa por todas las combinaciones con los valores de sus bits
			int suma=0;
			for(int j=1; j<=i; j=j<<1)if(j&i){ //j revisa el estado de cada bit de i
				int s=log2(j);
				suma+=bars[s]; //suma el valor en la posicion de bars correspondiente
			}	
			if(suma==n){
				cout << "YES\n";//si la combinacion da el resultado, imprime yes
				q=false;
				break;
			}	
		}
		if(q)cout << "NO\n";// si ninguna combinacion dió el resultado, imprime no
		--t;
	}
	return 0;
}