#include <bits/stdc++.h>
//Diego Henríquez
using namespace std;
//Hecho por mi
int main(){
	int t;
	cin >> t;
	while(t){//test cases
		int n;
		int city[25];//usé un arreglo en vez de una matriz para la ciudad
		cin >> n;//lee entrada
		int r,c;
		for(int i=0; i<25; ++i)city[i]=0;//inicializa en 0
		for(int i=0; i<n; ++i){
			cin >> r >> c;
			cin >> city[(r*5)+c];//lee los valores de las casillas
		}	
		int offices[5],menordistanciatotal=2000000;
		int i[5];
		for(i[0]=0; i[0]<21; ++i[0])for(i[1]=i[0]+1; i[1]<22; ++i[1])for(i[2]=i[1]+1; i[2]<23; ++i[2])for(i[3]=i[2]+1; i[3]<24; ++i[3])for(i[4]=i[3]+1; i[4]<25; ++i[4]){//5 iteradores que recorren el arreglo city pasando por todas las combinaciones
			int distanciatotal=0;
			for(int j=0; j<25; ++j)if(city[j]){
				//cout << "if\n";
				int menordistancia=abs((j/5)-i[0]/5)+abs(j%5-i[0]%5);//menor distancia parte como la distancia entre la casilla j y la primera oficina
				for(int k=1; k<5; ++k){
					int distancia=abs((j/5)-i[k]/5)+abs(j%5-i[k]%5);
					if(distancia<menordistancia)menordistancia=distancia; //se compara con la distancia de la casilla j a las otras oficinas y se queda con la menor
				}
				distanciatotal+=menordistancia*city[j]; //suma la menor distancia de esa casilla a una oficina
			}
			//else cout << "else\n";	
			if(distanciatotal<menordistanciatotal){//compara la distancia total de todas las casillas a las oficinas de esa combinacion
				menordistanciatotal=distanciatotal;//se queda con la menor
				for(int j=0; j<5; ++j){
					offices[j]=i[j];// guarda las posiciones de las oficinas que den la menor distancia total
				}
			}	
			/*for(int j=0; j<5 ; ++j)cout << i[j] << " ";	
			cout << ":	" << distanciatotal << "\n";*/
		}
		for(int i=0; i<4; ++i){
			cout << offices[i] << " ";//imprime el resultado
		}
		cout << offices[4] << "\n";
		--t;
	}
	return 0;
}