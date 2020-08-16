#include <bits/stdc++.h>
//Diego Henríquez Valenzuela ID: 988567
using namespace std;
//Hecho por mi

int main(){
	string verb, meaning;
	bool q=false;
	while(cin >> verb){//test cases
		if(q)cout << "\n";
		q=true;
		cin >> meaning;//lee entrada
		cout << verb << " (to " << meaning << ")\n";
		if(verb[verb.size()-1]=='r'){//revisa condición
			char tv = verb[verb.size()-2];
			verb.pop_back();
			verb.pop_back();//verb ahora es root
			char o = 243;//caracter para nós y vós
				if(tv=='i')cout << "eu        " << verb << "o\ntu        " << verb << "es\nele/ela   " << verb <<"e\nn" << o <<"s       " << verb << tv << "mos\nv" << o <<"s       " << verb << tv << "s\neles/elas " << verb << "em\n";
				else if(tv=='a' || tv=='e')cout << "eu        " << verb << "o\ntu        " << verb << tv << "s\nele/ela   " << verb << tv << "\nn" << o << "s       " << verb << tv << "mos\nv" << o << "s       " << verb << tv << "is\neles/elas " << verb << tv << "m\n";
				else cout << "Unknown conjugation\n";//imprime resultado según condiciones
		}		
		else cout << "Unknown conjugation\n"; 	
	}	
	return 0;
}
