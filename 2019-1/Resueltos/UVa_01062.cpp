#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	int c=1;
	while(s.compare("end")){
		int v[s.size()];
		for(int i=0;i<s.size();++i)v[i]=91;
		for(int i=0;i<s.size();++i){
			for(int j=0;j<s.size();++j){
				if(s[i]<=v[j]){
					v[j]=s[i];
					break;
				}
			}
		}
		int stacks=0;
		for(int i=0;i<s.size();++i)if(v[i]!=91)++stacks;
		cout << "Case " << c << ": " << stacks << "\n";
		++c;
		getline(cin,s);		
	}
	return 0;
}
// PRIMER ORDEN DESPUES LETRA. OTRO CODIGO