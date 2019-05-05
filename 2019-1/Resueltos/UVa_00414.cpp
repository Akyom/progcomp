#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	getchar();
	while(n){
		int i=0,blanco[n],menor=23;
		while(i<n){
			string c;
			getline(cin,c);
			blanco[i]=0;
			for(int j=0;j<25;++j)if(c[j]==' ')++blanco[i];
			if(blanco[i]<menor)menor=blanco[i];
			++i;
			//cout << "fin de una linea \n";
		}
		int suma=0;
		//cout << "menor: " << menor << "\n";
		for(int j=0;j<n;++j){
			//cout << "fila: " << j << " blancos: " << blanco[j] << "\n";
			suma+=(blanco[j]-menor);
			//cout << "suma: " << suma << "\n\n";
		}	
		cout << suma << "\n";
		cin >> n;
		getchar();
	}
	return 0;
}