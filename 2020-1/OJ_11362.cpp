#include <bits/stdc++.h>
//Diego Henríquez Valenzuela ID: 988567
using namespace std;
//Hecho por mi

int main(){
	int t;
	cin >> t;
	while(t){//test cases;
		int n;
		cin >> n;
		pair<int,string> agenda[n];
		for(int i=0; i<n; ++i){
			cin >> agenda[i].second;//lee entrada como string
			agenda[i].first=0;
			int k=10-agenda[i].second.size();
			for(int d=1,j=agenda[i].second.size()-1; j>=0; --j,d*=10){
				agenda[i].first+=(agenda[i].second[j]-48)*d;//guarda la entrada tambien como entero
			}
			while(k){
				agenda[i].first*=10;//convierte todos los enteros en numeros de 10 digitos
				--k;
			}
		}
		sort(&agenda[0],&agenda[n]);//ordena los numeros por su valor como entero
		bool q=false;
		for(int i=0; i<n-1; ++i){//un numero mayor no puede ser prefijo de uno menor, además si un numero no es prefijo del numero siguiente, entonces no es prefijo de ningún otro
			if(agenda[i].second.size()<=agenda[i+1].second.size()){//si el numero siguiente tiene menos digitos que el actual, entonces el actual no puede ser prefijo del siguiente
				q=true;
				for(int j=0; j<agenda[i].second.size(); ++j){
					if(agenda[i].second[j]!=agenda[i+1].second[j]){//compara cada digito del numero actual para ver si es prefijo del siguiente
						q=false;//si no es prefijo sale con q false, si es prefijo el for termina con q true
						break;
					}
				}
				if(q)break;//si encontró un prefijo sale con q true
			}
		}
		if(q) cout << "NO\n";//imprime resultado
		else cout << "YES\n";
		--t;
	}
}
