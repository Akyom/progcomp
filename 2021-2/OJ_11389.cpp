//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, d, r;
	cin >> n >> d >> r;
	while(n){//test cases
		int morning[n], evening[n];
		for(int i=0; i<n; ++i)cin >> morning[i];
		for(int i=0; i<n; ++i)cin >> evening[i];//lee entrada
		sort(&morning[0], &morning[n]);
		sort(&evening[0], &evening[n]);//ordena los arreglos
		int suma = 0;
		for(int i=0; i<n; ++i){
			int hours = morning[i]+evening[n-1-i];//suma los arreglos en orden inverso
			if(hours > d) suma += (hours - d);//calcula las horas que sobran
		}
		cout << suma*r << "\n";//imprime resultado
		cin >> n >> d >> r;
	}

}