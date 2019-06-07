#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
	int t;
	cin >> t;
	vector<int>* v = new vector<int>;
	while(t){
		int n;
		for(int i=0;i<t;++i){
			cin >> n;
			v->push_back(n);
		}
		sort(v->begin(),v->end());
		for(int i=0;i<(v->size()-1);++i){
			cout << v->at(i) << " ";
		}
		cout << v->at(v->size()-1) << "\n";
		v->clear();
		cin >> t;
	}
	return 0;
}