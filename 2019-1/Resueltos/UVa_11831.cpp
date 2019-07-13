#include <iostream>
#include <string>

using namespace std;

void changeOri(char* pori,char turn){
	if(turn=='D'){
		if(*pori=='N')*pori='L';
		else if(*pori=='L')*pori='S';
		else if(*pori=='S')*pori='O';
		else if(*pori=='O')*pori='N';
	}
	else{
		if(*pori=='N')*pori='O';
		else if(*pori=='L')*pori='N';
		else if(*pori=='S')*pori='L';
		else if(*pori=='O')*pori='S';
	}
}

void forward(string* arena, int* x, int* y, char ori, int* stickers, int xmax, int ymax){
	if(ori=='N'){
		if(*y>0){
			if(arena[*y-1][*x]=='.')--*y;
			else if(arena[*y-1][*x]=='*'){
				--*y;
				arena[*y][*x]='.';
				++*stickers;
			}	
		}
	}
	else if(ori=='S'){
		if(*y<ymax){
			if(arena[*y+1][*x]=='.')++*y;
			else if(arena[*y+1][*x]=='*'){
				++*y;
				arena[*y][*x]='.';
				++*stickers;
			}	
		}
	}
	else if(ori=='L'){
		if(*x<xmax){
			if(arena[*y][*x+1]=='.')++*x;
			else if(arena[*y][*x+1]=='*'){
				++*x;
				arena[*y][*x]='.';
				++*stickers;
			}	
		}
	}
	else if(ori=='O'){
		if(*x>0){
			if(arena[*y][*x-1]=='.')--*x;	
			else if(arena[*y][*x-1]=='*'){
				--*x;
				arena[*y][*x]='.';
				++*stickers;
			}	
		}
	}
}

int main(){
	int n,m,s;
	cin >> n >> m >> s;
	while(n){
		string arena[n];
		for(int i=0;i<n;++i)cin >> arena[i];
		int abs,ord;
		char ori;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(arena[i][j]!='.' && arena[i][j]!='#' && arena[i][j]!='*'){
					abs=j;
					ord=i;
					ori=arena[i][j];
					arena[i][j]='.';
					goto fuera;
				}
			}
		}
		fuera:
		string inst;
		cin >> inst;
		int stickers=0;
		for(int i=0;i<s;++i){
			if(inst[i]=='F')forward(arena,&abs,&ord,ori,&stickers,m-1,n-1);
			else changeOri(&ori,inst[i]);
		}
		cout << stickers << "\n";
		cin >> n >> m >> s;
	}
	return 0;
}