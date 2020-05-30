#include <bits/stdc++.h>
//Diego Henríquez ID: 988567
using namespace std;
//Hecho por mi
int main(){
	vector<pair<string,string> > sequence;
	string s1,s2;
	while(cin >> s1){//hasta eof
		cin >> s2;
		sequence.push_back(make_pair(s1,s2));//guarda los pares de strings
	}
	for(int i=0; i<sequence.size(); ++i){
		int k=0;//contador de la posicion en la string original
		bool subsequence=false;
		for(int j=0; j<sequence[i].second.size() ; ++j){//busca en cada char de la string que pretende encriptar a la original
			if(sequence[i].first[k]==sequence[i].second[j]){//si encuentra el char de la string original, pasa al siguiente
				++k;
				if(k==sequence[i].first.size()){//si encontró el ultimo char de la string original, la segunda string si es subsequence de la primera
					subsequence=true;
					break;
				}
			}
		}
		if(subsequence)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}