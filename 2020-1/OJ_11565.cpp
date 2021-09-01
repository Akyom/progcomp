//Diego Henríquez Valenzuela
//Hecho por mi
//Aceptado por juez
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){//test cases
		int a,b,c,x,y,z;
		bool q=false;
		cin >> a >> b >> c;//lee entrada
		int l=(int)sqrt(c-2);// l=limite de x
		//cout << "l: " << l << "\n";
		for(x=-l;x<=l;++x){//x desde el limite inferior hasta el limite superior (dado por la ecuacion 3)
			if(x && !(b%x)){
				//cout << "x: "<< x << "\n";
				int ax=abs(x);
				for(y=-(b/ax);y<=(b/ax);++y){//y desde el limite inferior hasta el limite superior (dado por la ecuacion 2)
					if(y&&y!=x){
						if(!(b%(x*y))){
							//cout << "y: " << y << "\n";
							z=a-x-y;//z dado por la ecuacion 1 ya teniendo x e y
							//cout << "z: " << z << "\n";
							if(z!=y && z!=x && x*y*z==b && (x*x)+(y*y)+(z*z)==c){ //comprueba las ecuaciones 2 y 3
								cout << x << " " << y << " " << z << "\n"; // si encuentra una solucion la imprime y pasa al siguiente caso
								q=true;
								break;
							}
						}
					}	
				}
				if(q)break;
			}	
		}
		if(!q)cout << "No solution.\n"; //si no encontró solucion imprime no solution
		--n;
	}
	return 0;
}
