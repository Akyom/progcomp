#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	int n;
	cin >> n;
	getchar();
	getchar();
	cout << setprecision(4) << fixed;
	while(n){
		string s;
		vector<pair<string,int> > vs;
		int total=0;
		while(getline(cin,s)){
			if(s.size()==0)break;
			bool p=true;
			for(int i=0;i<vs.size();++i){
				if(s==vs[i].first){
					p=false;
					++vs[i].second;
					++total;
					break;
				}	
			}	
			if(p){
				vs.push_back(make_pair(s,1));
				++total;
			}
		}
		sort(vs.begin(),vs.end());
		for(int i=0;i<vs.size();++i){
			cout << vs[i].first << " " << ((float)(vs[i].second)/(float)total)*100 << "\n";
		}
		--n;
		if(n)cout << "\n";
	}
	return 0;
}