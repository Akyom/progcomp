//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n){//test cases
		int dimensions[n];
		for(int i=0; i<n; ++i)cin >> dimensions[i];//lee entrada
		sort(&dimensions[0], &dimensions[n]);//ordena las dimensiones

		int c = 1, max = 1;
		for(int i=1; i<n; ++i){
			if(dimensions[i]==dimensions[i-1])++c;//calcula la mayor cantidad de repeticiones del mismo número
			else{
				if(c>max)max=c;
				c = 1;
			}
		}
		if(c>max)max=c;

		vector<vector<int> > vv;
		for(int i=0; i<max; ++i){//crea un vector de vectores con max vectores dentro, siendo max la cantidad maxima de repeticiones
			vector<int> aux;
			vv.push_back(aux);
		}

		for(int i=0; i<n; ++i){
			vv[i%max].push_back(dimensions[i]); //recorre el vector de vectores de forma circular agregando las dimensiones a los vectores
		}
	
		cout << max << "\n";//imprime resultado
		for(int i=0; i<max; ++i){
			for(int j=0; j<vv[i].size()-1; ++j){
				cout << vv[i][j] << " ";
			}
			cout << vv[i][vv[i].size()-1] << "\n";
		}
		cin >> n;
		if(n)cout << "\n";
	}	
}