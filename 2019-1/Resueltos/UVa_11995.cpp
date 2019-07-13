#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		int i=0,f,ce=3;;
		bool pila=true,cola=true,prioridad=true;
		while(i<t){
			cin >> f;
			int aux;
			cin >> aux;
			if(f==1){
				s.push(aux);
				q.push(aux);
				pq.push(aux);
			}
			if(f==2){
				if(pila){
					//cerr << "stack top: " << s.top() << "\n";
					if(s.empty()){
						pila=false;
						--ce;
					}
					else{
						if(s.top()!=aux){
						pila=false;
						--ce;
						}	
						s.pop();
					}	

				}	
				if(cola){
					//cerr << "cola front: " << q.front() << "\n";
					if(q.empty()){
						cola=false;
						--ce;
					}
					else{
						if(q.front()!=aux){
							cola=false;
							--ce;
						}	
						q.pop();
					}	
				}	
				if(prioridad){
					//cerr << "prioridad top: " << pq.top() << "\n";
					if(pq.empty()){
						prioridad=false;
						--ce;
					}
					else{
						if(pq.top()!=aux){
							prioridad=false;
							--ce;
						}	
						pq.pop();
					}	
				}
				/*if(!ce){
					break;
				}*/	
			}
			++i;
		}
		if(!ce)cout << "impossible\n";
		else{
			if(ce==1){
				if(pila)cout << "stack\n";
				if(cola)cout << "queue\n";
				if(prioridad)cout << "priority queue\n";
			}
			else cout << "not sure\n";
		}
	}
	return 0;
}