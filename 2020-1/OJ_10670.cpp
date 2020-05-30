#include <bits/stdc++.h>
//Diego Henríquez ID: 988567
using namespace std;
//Hecho por mi
class agency{
	public:
		string name;
		int A;
		int B;
};

int workreduction(int workload, int target, int A, int B){//calcula el precio de reducir el trabajo dados los precios A y B
	int price=0;
	while(workload!=target){
		if((target<=workload/2)&&(B<=(A*(workload-(workload/2))))){//EL servicio B solo es contratable sial reducir el trabajo por la mitad no nos queda menos trabajo que el target y no nos combiene contratarlo si contratar A la cantidad de veces necesarias es mas barato
			price+=B;//contrata el servicio B 1 vez
			workload=workload/2;
		}
		else{
			price+=A*(workload-target);//contrata el servicio A todas las veces que sean necesarias
			workload=target;
		}
	}
	return price;
}

int main(){
	int c;
	cin >> c;
	for(int k=1;k<=c;++k){//test cases
		int n,m,l;
		cin >> n >> m >> l;
		agency ag[l];
		for(int i=0; i<l; ++i){//lee entrada
			getchar();//evita el salto de linea anterior
			getline(cin,ag[i].name,':');//lee hasta el caracter ':''
			cin >> ag[i].A;
			getchar();//evita la coma
			cin >> ag[i].B;
		}
		pair<int,string> agsorted[l];
		for(int i=0; i<l; ++i){
			agsorted[i].first=workreduction(n,m,ag[i].A,ag[i].B);//guarda en first el precio
			agsorted[i].second=ag[i].name;//y en second el nombre
		}
		sort(&agsorted[0],&agsorted[l]);//luego ordena segun el precio, si 2 agencias tienen el mismo precio las ordenará por el nombre.

		cout << "Case " << k << "\n";
		for(int i=0; i<l; ++i)cout << agsorted[i].second << " " << agsorted[i].first << "\n";//imprime
	}
	return 0;
}