#include <iostream>
#include <string>

using namespace std;

int main(){
	int c;
	cin >> c;
	while(c){
		int l,m;
		cin >> l >> m;
		int left[m],right[m],cleft=0,cright=0;
		for(int i=0;i<m;++i){
			left[i]=-1;
			right[i]=-1;
		}
		int lcar;
		string side;
		for(int i=0;i<m;++i){
			cin >> lcar;
			getline(cin,side);
			//cout << side;
			if(!side.compare(" left")){
				left[cleft]=lcar;
				++cleft;
			}
			else{
				right[cright]=lcar;
				++cright;
			}
		}
		l=l*100;
		int laux=l,fleft=0,fright=0,r=0;
		bool currentside=true;
		/*cout << "Current side: Left\n";
		cout << "LEFT:\n cleft: " << cleft << "\nfleft: " << fleft << "\nleft:";
		for(int i=0; i<m;++i)cout << " " << left[i];
		cout << "\n";
		cout << "RIGHT:\n cright: " << cright << "\nfright: " << fright << "\nright:";
		for(int i=0; i<m;++i)cout << " " << right[i];
		cout << "\nr:" << r << "\n";*/
		while(cleft||cright){
			if(currentside){
				while((laux>=left[fleft])&&cleft){
					laux-=left[fleft];
					++fleft;
					--cleft;
				}
				currentside=false;
			}
			else{
				while((laux>=right[fright])&&cright){
					laux-=right[fright];
					++fright;
					--cright;
				}
				currentside=true;
			}
			laux=l;
			++r;
			/*if(currentside)cout << "Current side: Left\n";
			else cout << "Current side: Right\n";
		cout << "LEFT:\n cleft: " << cleft << "\nfleft: " << fleft << "\nleft:";
		for(int i=0; i<m;++i)cout << " " << left[i];
		cout << "\n";
		cout << "RIGHT:\n cright: " << cright << "\nfright: " << fright << "\nright:";
		for(int i=0; i<m;++i)cout << " " << right[i];
		cout << "\nr:" << r << "\n";*/
		}
		cout << r << "\n";
		--c;
	}
	return 0;
}