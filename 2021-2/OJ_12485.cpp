//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez

#include <iostream>

using namespace std;

int main() {
	int n;
	while(cin >> n){//test cases
		int notes[n],promedio=0;
		for(int i=0; i<n; ++i){
			cin >> notes[i]; //lee entrada
			promedio+=notes[i];
		}
		promedio=promedio/n;//calcula el promedio
		int dif1=0,dif2=0;
		for(int i=0; i<n; ++i){
			if(notes[i]<promedio)dif1+=promedio-notes[i];//calcula cuantas notas tienen que bajar los coristas
			if(notes[i]>promedio)dif2+=notes[i]-promedio;//calcula cuantas notas tienen que subir los coristas
		}
		if(dif1==dif2)cout << dif1+1 << "\n";//imprime resultado
		else cout << "-1\n";
	}
}	