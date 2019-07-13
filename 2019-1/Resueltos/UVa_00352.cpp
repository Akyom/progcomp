#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void eraseEagle(int x, int y,int n ,bool image[][25]){
	image[x][y]=false;
	//cerr << "borra en " << x << " " << y << "\n";
	for(int i=x-1;i<=x+1 ;++i){
		if(i>=0 && i<n)for(int j=y-1;j<=y+1;++j){
			if(j>=0 && j<n)if(image[i][j])eraseEagle(i,j,n,image);	
		}
	}
}

int main(){
	int n,k=0;
	while(scanf("%d",&n)!=EOF){
		++k;
		bool image[n][25];
		string saux;
		for(int i=0;i<n;++i){
			cin >> saux;
			for(int j=0;j<n;++j){
				image[i][j]=(saux[j]-48);
			} 
		}
		int eagles=0;
		for(int i=0;i<n;++i)for(int j=0;j<n;++j){
			if(image[i][j]){
				//cerr << "encuentra aguila en " << i << " " << j << "\n";
				eraseEagle(i,j,n,image);
				++eagles;
			}
		}
		cout << "Image number " << k << " contains " << eagles << " war eagles.\n";
	}
	return 0;
}