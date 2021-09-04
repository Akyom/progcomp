//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez
#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

class TMT{//clase que guarda un orden en un vector y el total miss time de ese orden en cada nivel de importancoa, a=1, b=2...
	public:
	TMT(){
		a=0;
		b=0;
		c=0;
		d=0;
		e=0;
	}
	int a;
	int b;
	int c;
	int d;
	int e;
	vector<int> orden;
};

bool menorTMT(TMT tmt1, TMT tmt2){//compara 2 TMT devolviendo verdadero si la primera es menor que la segunda.
	if(tmt1.a==tmt2.a){
		if(tmt1.b==tmt2.b){
			if(tmt1.c==tmt2.c){
				if(tmt1.d==tmt2.d){
					return tmt1.e<tmt2.e;
				}
				else return tmt1.d<tmt2.d;
			}
			else return tmt1.c<tmt2.c;
		}
		else return tmt1.b<tmt2.b;
	}
	else return tmt1.a<tmt2.a;
}

void swap(int* a, int* b){//función swap
	int aux=*a;
	*a=*b;
	*b=aux;
}

TMT calcularTMT(int* lengths, pair<int, int>* alignement, int n, int a){//dado un orden (que se le pasa en lengths), un conjunto de puntos de alineamiento y sus prioridades, la función calcula cual es el total miss time para cada prioridad.
	//cerr << "calcularTMT\n";
	int suma=0,prev,k=0;
	TMT t;//t es la TMT que se va a retornar
	for(int j=0; j<n; ++j)t.orden.push_back(lengths[j]);//se guarda el orden en t
	bool q=false;
	for(int i=0; i<n; ++i){
		prev=suma;//se van agregando duraciones, en suma se guarda la suma hasta la ultima duración agregada y en prev, su valor previo.
		//cerr << "suma: " << suma << " lengths[i]: " << lengths[i] << " k: " << k <<"\n";
		suma+=lengths[i];
		//cerr << "suma: " << suma << " alignement[k]: " << alignement[k].first << "\n";
		while(suma>=alignement[k].first){
			if(suma>alignement[k].first){//si suma es mayor a el siguiente punto de alineamiento, se calcula si la diferencia es menor con suma o con prev.
				int diff=min(suma-alignement[k].first,alignement[k].first-prev);
				//cerr << "diff: " << diff << " prioridad: " << alignement[k].second << " k: " << k <<"\n";
				switch(alignement[k].second){//se guarda la diferencia en la prioridad correspondiente
					case 1:	t.a+=diff; break;
					case 2:	t.b+=diff; break;
					case 3:	t.c+=diff; break;
					case 4:	t.d+=diff; break;
					case 5:	t.e+=diff; break;
				}
			}
			++k;//se pasa al siguiente punto de alineamiento. Si el punto de alineamiento era igual a suma entonces no había nada que sumar.
			//cerr << "t.a: " << t.a << " t.b: " << t.b << " t.c: " << t.c<< " t.d: " << t.d << " t.e: " << t.e <<"\n";
			if(k>=a){//si ya no quedan puntos de alineamiento
				//cerr << "break\n";
				q=true;
				break;
			}
		}
		if(q)break;
	}
	return t;
}

TMT permutar(int* lengths, int* plengths, pair<int, int>* alignement, int n, int a){//función recursiva que cambia el orden de las duraciones
	//cerr << "permutar\n";
	if(plengths==lengths+n-1)return calcularTMT(lengths, alignement, n, a);//si ya se tiene un orden, se calculan sus TMT para cada prioridad.	
	else{
		TMT menor;
		menor.a=INT_MAX; menor.b=INT_MAX; menor.c=INT_MAX; menor.d=INT_MAX; menor.e=INT_MAX;
		for(int i=plengths-lengths; i<n; ++i){//Se busca una duración que fijar en la posición actual. Se itera sobre todas las duraciones no fijadas.
			swap(plengths,&lengths[i]);
			TMT aux=permutar(lengths,plengths+1,alignement,n,a);//Se fija una duración y se llama recursivamente con plengths+1 para buscar una duración para la siguiente posición.
			if(menorTMT(aux,menor)){//Se busca el orden con el menor total miss time considerando prioridades.
				/*cerr << "menor\n";
				cerr << aux.a << " " << aux.b << " " << aux.c << " " << aux.d << " " << aux.e << "\nOrden: ";
				for(int i=0; i<n; ++i)cerr << aux.orden[i] << " ";
				cerr <<"\n";*/
				menor=aux;
			}
			swap(&lengths[i],plengths);
		}
		//cerr << "return\n";
		return menor;
	}
}

int main() {
	int n;
	cin >> n;
	int d=0;
	while(n){//test cases
		cout << "Data set " << ++d << "\n";
    	int lengths[n];
    	for(int i=0; i<n; ++i)cin >> lengths[i];//lee duraciones
    	int a;
    	cin >> a;
    	pair <int, int> alignement[a];
    	for(int i=0; i<a; ++i)cin >> alignement[i].second >> alignement[i].first;
		sort(&alignement[0],&alignement[a]);//lee puntos de alineamiento
    	TMT resultado=permutar(lengths,lengths,alignement,n,a);//llama a la funcion recursiva que buscará entre todos los ordenes de las duraciones y devolverá aquel que tenga menor total miss time segun prioridades, considerando los puntos de alineamiento.
		int error=resultado.a+resultado.b+resultado.c+resultado.d+resultado.e;
		cout << "Order:";//Imprime resultado
		for(int i=0; i<n; ++i){
			cout << " " << resultado.orden[i] ;
		}
		cout << "\nError: " << error << "\n";
    	cin >> n;
  	}
}