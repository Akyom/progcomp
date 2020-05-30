#include <bits/stdc++.h>
//Diego Henríquez ID:988567
using namespace std;
//Hecho por mi
int main(){
	int n;
	cin >> n;
	while(n){ //test cases
		int m;
		cin >> m;
		vector<pair<int,int> > segments;
		int l,r;
		cin >> l >> r;
		while(l||r){ //hasta que l r sea 0 0
			segments.push_back(make_pair(l,r));//se guardan los segmentos en segments
			cin >> l >> r;
		}
		vector<pair<int,int> > answer;
		bool covered=true;
		sort(segments.begin(),segments.end());//se ordenan los segmentos segun first
		int current=0,mayor=0,posmayor;//current es hasta donde hemos cubierto
		while(current<m){
			bool haymayor=false;
			for(int i=0; i<segments.size(); ++i){
				if(segments[i].first>current)break;//se busca dentro de los segmentos que tienen first menor o igual que current
				if(segments[i].second>mayor){//al segmento con el mayor second (el que cubrirá mas)
					mayor=segments[i].second;
					posmayor=i;
					haymayor=true;
				}
			}
			if(haymayor){//si algun segmento tiene first<=current y second >current, osea que cubre el siguiente pedazo 
				current=mayor;//actualiza current
				answer.push_back(segments[posmayor]);//se añade a la lista de segmentos
			}
			else{//si ningun segmento cubre el siguiente pedazo
				covered=false;//no se cubrió [0,m]
				break;
			}
		}

		if(covered){//si es que se cubrió [0,m]
			cout << answer.size() << "\n";
			for(int i=0; i<answer.size(); ++i){
				cout << answer[i].first << " " << answer[i].second << "\n";
			}
		}
		else cout << "0\n";//si es que no
		cout << "\n";
		--n;
	}
	return 0;
}