#include <bits/stdc++.h>
//Diego Henríquez Valenzuela ID: 988567
using namespace std;
//Hecho por mi
class row{
	public:
	float duration;
	int a;
	int b;
};

class key{
	public:
		int time;
		//key* anterior;
		vector<pair<int,key*> > rows;
};

void dijkstra(key root,int n){
	//root.anterior=NULL;
	vector<key*> vk;
	for(int i=0; i<root.rows.size(); ++i){//mete en vk las key conectadas a root(la key numero 1) por una row 
		key* pkey=root.rows[i].second;
		pkey->time=root.rows[i].first;//actualiza time
		//pkey->anterior=root;//actualiza anterior
		vk.push_back(pkey);
	}	
	while(!vk.empty()){
		int menor=vk[0]->time,posmenor=0;
		for(int i=1; i<vk.size(); ++i){
			if(vk[i]->time<menor){//busca en el arreglo vk, la key con el menor time
				menor=vk[i]->time;
				posmenor=i;
			}	
		}
		key* next=vk[posmenor];
		vk.erase(vk.begin()+posmenor);//saca next de vk
		for(int i=0; i<next->rows.size(); ++i){//mete en vk las key conectadas a next
			key* pkey=next->rows[i].second;
			if(pkey->time==INT_MAX){//caso en que la key no esta ya en vk
				pkey->time= next->rows[i].first + next->time;
				//pkey->anterior=
				vk.push_back(pkey);
			}
			else if(pkey->time > next->rows[i].first + next->time){//caso en que la key ya esta en vk pero este es un camino mas corto
				pkey->time= next->rows[i].first + next->time;
			}//si es que la key ya está en vk y este es un camino mas largo no se hace nada

		}
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	int t=1;
	while(n){//test cases
		key keys[n];
		keys[0].time=0;
		for(int i=1; i<n; ++i)keys[i].time=INT_MAX;//inicializa time en keys
		int a,b,l;
		row rows[m];
		for(int i=0; i<m; ++i){
			cin >> a >> b >> l;
			--a;--b;
			rows[i].duration=l;
			rows[i].a=a;
			rows[i].b=b;
			keys[a].rows.push_back(make_pair(l,&keys[b]));//conecta las keys por punteros
			keys[b].rows.push_back(make_pair(l,&keys[a]));
		}

		dijkstra(keys[0],n);
		/*for(int i=0; i<n; ++i){
			cout << "Key: " << i+1 << " Time: " << keys[i].time << "\n";
		}*/
		vector<row> vrow;
		for(int i=0; i<m; ++i){
			//cout << "row desde "<< rows[i].a+1 << " hasta " << rows[i].b+1 << "\n";
			int t1=keys[rows[i].a].time;
			int t2=keys[rows[i].b].time;
			if(abs(t1-t2)<rows[i].duration){                               //busca las rows que terminan de caer a la mitad y no a un extremo
				//cout << "termina en la mitad en ";
				rows[i].duration=max(t1,t2)+(rows[i].duration-abs(t1-t2))/2;//calcula en que tiempo terminan de caer
				//cout << rows[i].duration <<"\n";
				vrow.push_back(rows[i]);//las mete en vrow
			}
		}
		float mayor=0;
		int posmayor=0;
		bool eskey=true;
		for(int i=1;i<n;++i){//busca la key que cae al ultimo
			if(keys[i].time>mayor){
				mayor=keys[i].time;
				posmayor=i;
			}
		}
		for(int i=0;i<vrow.size();++i){//busca si alguna row, de las que terminan de caer a la mitad, termina de caer despues de que cae la ultima key
			if(vrow[i].duration>mayor){
				mayor=vrow[i].duration;
				posmayor=i;
				eskey=false;
			}
		}
		cout << fixed << setprecision(1);
		cout << "System #" << t << "\nThe last domino falls after " << mayor <<" seconds, ";//imrpime resultado
		if(eskey)cout << "at key domino " << posmayor+1 << ".\n\n";
		else cout << "between key dominoes " << vrow[posmayor].a+1 << " and " << vrow[posmayor].b+1 << ".\n\n";
		cin >> n >> m;
		++t;
	}
	return 0;
}
