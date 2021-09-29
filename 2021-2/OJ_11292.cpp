//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	while(n && m){//test cases
		int heads[n], knights[m];
		for(int i=0; i<n; ++i)cin >> heads[i];
		for(int i=0; i<m; ++i)cin >> knights[i];//lee entrada
		bool doomed = true;
		int suma = 0;
		if(m>=n){//si hay mas cabezas que caballeros Loowater is doomed
			sort(&heads[0], &heads[n]);
			sort(&knights[0], &knights[m]);//se ordenan las cabezas y los caballeros
			int k = 0, i;
			for(i=0; i<n; ++i){//por cada cabeza
				bool chopped = false;
				for(int j=k; j<m; ++j){//se busca entre los caballeros
					if(knights[j]>=heads[i]){//el caballero mas bajo que pueda cortarla
						k=j+1;
						suma += knights[j];//si se encuentra se suma su estatura
						chopped = true;//y se corta la cabeza
						break;
					}
				}
				if(!chopped)break;//si la cabeza no pudo ser cortada Loowater is doomed
			}
			if(i==n)doomed=false;
		}
		if(doomed)cout << "Loowater is doomed!\n";
		else cout << suma << "\n";
		cin >> n >> m;
	}	
}