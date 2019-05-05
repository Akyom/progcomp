#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n,m;
	cin >> n;
	while(n){
		//cout << "Bloque\n";
		cin >> m;
		while(m){
			//cout << "Linea\n";
			int r=0;
			int v[n];
			v[0]=m;
			for(int i=1;i<n;++i)cin >> v[i];
			//cout << "la entrada es: ";
			//for(int i=0;i<n;++i)cout << v[i] << " ";
			//cout << "\n";
			int k=0,c=0;
			stack <int> s;
			//cout << "push\n";
			while(1){
				//cout << "ciclo\n";
				if(s.empty()){
					++k;
					s.push(k);
					//cout << "push\n" << "k: " << k << "\n";
				}
				if(k>n)break;
				if(v[c]==s.top()){
					s.pop();
					//cout << "pop\n";
					++c;
					//cout << "c: " << c << "\n";
					if(c==n){
						r=1;
						break;
					}
				}
				else{
					++k;
					s.push(k);
					//cout << "push\n" << "k: " << k << "\n";
				}
			}
			if(r)cout << "Yes\n";
			else cout << "No\n";
			cin >> m;
		}
		cout << "\n";
		cin >> n;
	}
	return 0;
}