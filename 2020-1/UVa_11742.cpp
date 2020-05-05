#include <bits/stdc++.h>
//Diego Henríquez
using namespace std;
//Hecho por mi
int mbam(int a){//multiply by all minors
	int p=1;
	while(a>1){
		p=p*a;
		--a;
	}
	return p;
}

class constraint{// a y b son los teens y d la distancia
	public:
		int a;
		int b;
		int d;
};

int findpos(int n, int v[] ,int a){//devuelve la posicion de a en v y -1 si a no se encuentra en v
	for(int i=0;i<n;++i){
		if(v[i]==a)return i;
	}
	return -1;
}

int checkconstraints(int m, constraint cv[], int n, int teenagers[]){//recibe un arreglo y comprueba si cumple con las constraints
	int a,b,d,c=0;
	for(int i=0;i<m;++i){
		a=findpos(n,teenagers,cv[i].a);//primero busca al teen a y al b en el arreglo, si no encuentra alguno, quiere decir que aun no se sienta así que pasa a la siguiente constraint
		if(a==-1)continue;
		b=findpos(n,teenagers,cv[i].b);
		d=cv[i].d;
		//cout << "a: " << a << "b: " << b << "d: " << d << "\n";
		if(b==-1)continue;
		if(d>0){//si no se cumple alguna constraint retorna 0
			if(abs(a-b)>d)return 0;
		}
		else if(abs(a-b)<-d)return 0;
		++c;
	}
	if(c==m)return 2; //si todas las constraints se cumplen retorna 2
	return 1; //si no se pudieron comprobar todas las constraints, pero las que se pudieron comprobar se cumplen, retorna 1
}

int tryteen(int n, int teenagers[], int m, constraint cv[],vector< pair<int,int> > teenq, int nextteen){//prueba las combinaciones de teens y devuelve la suma de las posibles
	int p=checkconstraints(m,cv,n,teenagers);
	if(p){//prueba si el arreglo recibido cumple con las constraints, si no, retorna 0
		if(p==2){// si el arreglo recibido cumple con todas las constraints y no hay mas constraints que comprobar, los demas teens pueden sentarse en cualquier orden
			//cout << "mbam\n";
			return mbam(n-(nextteen-1));//retorna la cantidad de combinaciones en las que se puede sentar el resto de teens
		}	
		if(nextteen==n){//si el ultimo teen se sienta y las constraints se cumplen, esta combinacion es correcta, retorna 1
			/*cout << "posicion: ";
			for(int i=0;i<n;++i){
				cout << teenagers[i] << " ";
			}
			cout << "\n";*/
			return 1;
		}
		int suma=0;
		for(int i=0;i<n;++i){//si las constraints se cumplen, pero aun hay constraints que probar y teens que sentar
			if(teenagers[i]!=-1)continue;//se salta las posiciones donde ya hay un teen sentado
			teenagers[i]=teenq[nextteen].second;//sienta al siguiente teen en la siguiente posición
			suma+=tryteen(n,teenagers,m,cv,teenq,nextteen+1);//se llama a si misma, ahora con el nuevo teen
			teenagers[i]=-1; //saca al teen que acaba de sentarse
		}
		return suma; //retorna todas las combinaciones posibles (con los 2 primeros teens en las posiciones recibidas)
	}
	else return 0;	
}

int main(){
	int n,m;
	cin >> n >> m;//lee entrada
	while(n+m>0){//termina si ambos son 0
		if(m==0)cout << mbam(n) << "\n";//si no hay constraints
		else{
			constraint cv[m];//arreglo que guarda kas constraints
			vector< pair<int,int> > teenq;//fila de teens que iremos agregando. En first guarda la cantidad de constraints que involucran a ese teen, en second el numero del teen
			int teenagers[n];//arreglo de teens que ya estan sentados
			for(int i=0;i<n;++i){
				pair<int,int> paux =make_pair(0,i);
				teenq.push_back(paux);
				teenagers[i]=-1;
			}
			for(int i=0;i<m;++i){
				cin >> cv[i].a >> cv[i].b >> cv[i].d;
				++teenq[cv[i].a].first;
				++teenq[cv[i].b].first;
			}
			sort(teenq.begin(),teenq.end());//ordena teenq por el first, así los teens con mas constraints de agregárán primero
			int suma=0;//guarda la cantidad de combinaciones posibles
			for(int i=0;i<n;++i){
				teenagers[i]=teenq[0].second;//el primer teen va a sentarse
				for(int j=0;j<n;++j){
					if(j==i)continue;
					teenagers[j]=teenq[1].second;//el segundo teen va a sentarse
					suma+=tryteen(n,teenagers,m,cv,teenq,2);
					teenagers[j]=-1;//saca al segundo teen
				}	
				teenagers[i]=-1;//saca al primer teen
			}
			cout << suma << "\n";//imprime todas las combinaciones posibles
		}
		cin >> n >> m;
	}
	return 0;
}