#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class nodo{
	public:
		char name;
		int hijos;
		nodo* padre;
	nodo(char c,nodo* n){
		padre=n;
		name=c;
		hijos=0;
	}	
};

int main(){
	int t,c=1;
	cin >> t;
	while(c<=t){
		string s;
		cin >> s;
		vector<pair<char,nodo*> > trail;
		nodo* pnodo =new nodo(s[0],NULL); 
		trail.push_back(make_pair(s[0],pnodo));
		for(int i=1;i<s.size();++i){
			if(s[i]==pnodo->name){
				pnodo=pnodo->padre;
				if(pnodo==NULL)break;
			}
			else {
				++(pnodo->hijos);
				pnodo=new nodo(s[i],pnodo);
				trail.push_back(make_pair(s[i],pnodo));
			}
		}
		sort(trail.begin(),trail.end());
		cout << "Case " << c << "\n";
		int adj;
		while(!trail.empty()){
			adj=(trail[0].second)->hijos;
			if(((trail[0].second)->padre) != NULL)++adj;
			cout << trail[0].first << " = " << adj << "\n";
			trail.erase(trail.begin());
		}	
		++c;
	}
	return 0;
}