#include <bits/stdc++.h>
//Diego Henríquez Valenzuela ID: 988567
using namespace std;
//Hecho por mi

int main(){
	int l,n;
	cin >> l >> n;
	map<string,string> traductor;
	string saux, saux2;
	while(l){
		cin >> saux >> saux2;//lee las traducciones especiales
		traductor.insert(make_pair(saux,saux2));
		--l;
	}
	string word;
	while(n){
		cin >> word;//palabra a traducir
		if(traductor.find(word)!=traductor.end())cout << traductor[word] << "\n";//la busca en las traducciones especiales y si está ahí imprime la traducción
		else{
			char last = word[word.size()-1];
			char cons = word[word.size()-2];
			if(last == 'y' && cons != 'a' && cons != 'e' && cons != 'i' && cons != 'o' && cons != 'u'){
				word.pop_back();
				cout << word << "ies\n";
			}	 
			else if(last == 'o' || last == 's' || last == 'x' || (last == 'h' && (cons == 'c' || cons == 's')))cout << word << "es\n";
			else cout << word << "s\n";//imprime resultado según condiciones
		}		
		--n;
	}

	return 0;
}