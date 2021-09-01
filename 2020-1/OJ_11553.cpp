//Diego Henríquez
//Hecho por mi
//Aceptado por juez
#include <bits/stdc++.h>

using namespace std;

void gridgame(int n, vector<vector<int> > grid, int* pcandies, int suma, int it){
	/*cerr << "gridgame it: " << it << "\n";
	for(int i=0; i<grid.size(); ++i){
		for(int j=0; j<grid[i].size(); ++j){
			cerr << grid[i][j]<< " ";
		}
		cerr << "\n";
	}*/
	if(grid.empty()){						//fondo de la recursividad.
		if(suma<*pcandies){					//pcandies guarda el menor resultado de todas las combinaciones
			*pcandies=suma;
			//cerr << "candies=" << *pcandies << "\n";
		}	
	} 
    else{
    	for(int j=0; j<n-it; ++j){
    		//cerr << "it: " << it << " j: " << j << " suma: " << suma <<" grid: " << grid[0][j] << "\n";
    		vector<vector<int> > newgrid;
    		
    		for(int i=1; i<n-it ;++i){     //guarda en newgrid una copia de la grid pero sin la fila ni la columna correspondientes a la casilla donde se cruzan las lineas
    			vector<int> vaux;
    			for(int j2=0; j2<n-it; ++j2){
    				if(j2!=j)vaux.push_back(grid[i][j2]);
    			}
    			newgrid.push_back(vaux);
    		}
    		gridgame(n,newgrid,pcandies,suma+grid[0][j], it+1);  //llama a gridgame con newgrid y agregandole a la suma el numero en la casilla

    	}
    }
}

int main(){
	int t;
	cin >> t;
	while(t){//test cases
		int n;
		cin >> n;
		vector<vector<int> > grid;
		for(int i=0; i<n; ++i){  //lee entrada
			vector<int> vaux;
			for(int j=0; j<n; ++j){
				int aux;
				cin >> aux;
				vaux.push_back(aux);
			}
			grid.push_back(vaux);
		}		
		int candies=8001; //aqui quedará el resultado despues de la recursividad
		gridgame(n,grid,&candies,0,0);
		cout << candies << "\n";
		--t;
	}
	return 0;
}
