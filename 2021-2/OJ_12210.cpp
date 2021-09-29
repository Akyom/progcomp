//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int b,s,aux,t=1;
	cin >> b >> s;
	while(b){//test cases
		if(b>s){//si sobran bachelors
			int bachelors[b];
			for(int i=0; i<b; ++i)cin >> bachelors[i];//lee entrada
			for(int i=0; i<s; ++i)cin >> aux;
			sort(&bachelors[0], &bachelors[b]);
			cout << "Case " << t << ": " << b-s << " " << bachelors[0] << "\n";//imprime resultado
		}
		else{//si no sobran bachelors
			for(int i=0; i<b+s; ++i)cin >> aux;
			cout << "Case " << t << ": " << "0\n";//se imprime 0
		}	
		cin >> b >> s;
		++t;
	}
}	