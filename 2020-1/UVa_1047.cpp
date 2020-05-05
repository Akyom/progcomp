#include <bits/stdc++.h>
//Diego Henríquez
using namespace std;
//Hecho por mi
class tower{
	public:
		int a;//cantidad de clientes unicos de esta torre
		vector<int> csa; //common service areas. guarda los numeros de las posiciones en el arreglo de areas que corresponden a las areas comunes en las que esta torre participa 
};


void trytower(int n, tower towers[], int areas[], bool a[], int t, int buildtowers[], int* customers, int it,int it2, int people, int towersbuilt[]){
	if(it==t){                                                   //si ya pusimos t torres 
		/*cerr << "towersbuilt: ";
		for(int i=0;i<t-1;++i)cout << towersbuilt[i] << " ";
		cerr << towersbuilt[t-1] << "\n";
		cerr << "people: " << people << "\n";*/	
		if(people>*customers){                        //guarda la mejor combinacion y el mayor numero de clientes en buildtowers y customers
			//cerr << "update customers\n";
			*customers=people;
			for(int i=0;i<t;++i)buildtowers[i]=towersbuilt[i];
		}
		//cerr << "sale del for\n";
	}
	else for(int i=it2;i<=n-t+it;++i){        //it2 depende del ciclo del nivel inferior. en cada nivel, el ciclo debe empezar con i siendo uno mas que el ciclo del nivel inferior. it guarda el nivel o cuantas torres han sido construidas, que es lo mismo
		people+=towers[i].a;					//se añade una torre
		vector<int> areasadded;
		for(int j=0; j<towers[i].csa.size(); ++j){ //se añaden todas las areas compartidas de la torre si es que no se han añadido ya
			int aux=towers[i].csa[j];
			if(a[aux]){
				people+=areas[aux];
				a[aux]=false;
				areasadded.push_back(aux);
			}
		}
		towersbuilt[it]=i; //se agrega a towersbuilt la torre añadida
		trytower(n,towers,areas,a,t,buildtowers,customers,it+1,i+1,people,towersbuilt); //se llama a trytower para añadir otra torre o para comparar la combinacion si es que ya añadimos la maxima cantidad de torres
		people-=towers[i].a;       //se quita la torre
		for(int j=0; j<areasadded.size(); ++j){//se quitan todas las areas añadidas con la torre
			people-=areas[areasadded[j]];
			a[areasadded[j]]=true;
		}
	}
}

int main(){
	int n,t,c=1;
	cin >> n >> t;
	while(n&&t){//test cases
		tower tv[n];//arreglo de torres
		for(int i=0; i<n; ++i)cin >> tv[i].a;//llena el arreglo de torres con todos los clientes de cada torre
		int m;
		cin >> m;
		int av[m];//arreglo de areas
		bool a[m];//arreglo que nos indica si el area en la misma posicion fue agregada ya(false) o no(true)
		for(int i=0; i<m; ++i){
			int ct;//cuantas torres participan del area comun i
			cin >> ct;
			int aux[ct];//guarda las torres que participan del area comun i
			for(int j=0; j<ct; ++j)cin >> aux[j];
			cin >> av[i];//guarda los clientes del area comun i
			for(int j=0; j<ct; ++j){//para cada torre que participa del area comun i
				tv[aux[j]-1].csa.push_back(i);//guarda la posicion del area
				tv[aux[j]-1].a-=av[i];//resta los clientes del area comun a los clientes de la torre (al final se debe quedar con los clientes que son unicos a la torre)
			}
			a[i]=true;//ninguna area comienza agregada
		}
		int buildtowers[t],customers=0,towersbuilt[t];//buildtowers almacenará las torres del resultado, customers, los clientes del resultado y towersbuilt las combinaciones de torres que iremos probando
		for(int i=0; i<t; ++i)buildtowers[i]=i+1;
		trytower(n,tv,av,a,t,buildtowers,&customers,0,0,0,towersbuilt);//prueba todas las combinaciones y deja los resulrados en buildtowers y customers
		cout << "Case Number  " << c << "\nNumber of Customers: " << customers << "\nLocations recommended: ";
		for(int i=0; i<t-1; ++i)cout << buildtowers[i]+1 << " ";
		cout << buildtowers[t-1]+1 << "\n\n";
		cin >> n >> t;
		++c;
	}
	return 0;
}	