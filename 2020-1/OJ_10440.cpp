#include <bits/stdc++.h>
//Diego Henríquez ID: 988567
using namespace std;
//Hecho por mi
int main(){
	int c;
	cin >> c;
	while(c){//test cases
		int n,t,m;
		cin >> n >> t >> m;
		int car[m];
		for(int i=0; i<m ; ++i)cin >> car[i];//lee entrada
		int delay=0;
		for(int i=m-1-n; i>=0 ; i-=n)delay+=(car[i]+2*t)-car[i+n];//calcula cuanto se atrasa en subir el ultimo auto al ferry desde que llegó
		if(delay<0)delay=0;//no puede subirlo antes de que llegue
		cout << delay+car[m-1]+t << " " << ((m%n)? (m/n)+1 : m/n) << "\n";//imprime resultado, la cantidad de viajes es solo m/n redondeado hacia arriba.
		--c;
	}	
	return 0;
}