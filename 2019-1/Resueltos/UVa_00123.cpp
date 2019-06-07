#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <utility>
using namespace std;


typedef struct{
	int wpos;
	int phrase;
	string w;
}word;

int main(){
	vector<vector<string> > kwic;
	vector<string> wti;
	vector<word> vw;
	string aux;
	cin >> aux;
	for(int i=0;aux.compare("::");++i){
		wti.push_back(aux);
		cin >> aux;
	}
	vector<string> v;
	char c;
	while(cin >> aux){
		for(int i=0;i<aux.size();++i){
			if(aux[i]<=90)aux[i]+=32;
		}
		bool p=true;
		for(int i=0;i<wti.size();++i)if(!aux.compare(wti[i])){
			p=false;
			break;
		}
		if(p){
			word wo;
			wo.wpos=v.size();
			wo.phrase=kwic.size();
			wo.w=aux;
			vw.push_back(wo);
		}
		v.push_back(aux);
		c=getchar();
		if(c=='\n'){
			kwic.push_back(v);
			while(!v.empty())v.erase(v.begin());
		}
	}
	kwic.push_back(v);
	while(!v.empty())v.erase(v.begin());
	/*for(int i=0;i<kwic.size();++i){
		for(int j=0;j<kwic[i].size();++j){
			cout << kwic[i][j] << " ";
		}
		cout << "\n";
	}*/
	//for(int i=0;i<vw.size();++i)cout << vw[i].w << "\n";
	if(!vw.empty()){
		for(int i=0;i<vw.size()-1;++i){
			//string menor=vw[i].w;
			int posmenor=i;
			word aux2;
			bool q=false;
			for(int j=i;j<vw.size();++j){
				if(vw[posmenor].w.compare(vw[j].w)>0)posmenor=j;
				else if(vw[posmenor].w.compare(vw[j].w)==0){
					if(vw[posmenor].phrase>vw[j].phrase)posmenor=j;
					else if(vw[posmenor].phrase==vw[j].phrase)if(vw[posmenor].wpos>vw[j].wpos)posmenor=j;
				}		
			}	
			aux2=vw[i];
			vw[i]=vw[posmenor];
			vw[posmenor]=aux2;
		}
	}
	//for(int i=0;i<vw.size();++i)cout << vw[i].w << " " << vw[i].phrase <<"\n";
	
	for(int i=0;i<vw.size();++i){
		for(int j=0;j<vw[i].w.size();++j){
			if(vw[i].w[j]>=97)vw[i].w[j]-=32;
		}
	}
	for(int i=0;i<vw.size();++i){
		for(int j=0;j<kwic[vw[i].phrase].size();++j){
			if(j==vw[i].wpos){
				cout << vw[i].w;
			}
			else cout << kwic[vw[i].phrase][j];
			if(j!=kwic[vw[i].phrase].size()-1)cout << " ";
		}
		cout << "\n";
	}
	return 0;
}