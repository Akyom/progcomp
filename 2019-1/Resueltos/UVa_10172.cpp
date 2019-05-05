#include <iostream>

using namespace std;

class cargo{
	private:
		int id;
	public:
		cargo(){
		}
		int getID(){
			return id;
		}	
		void setID(int a){
			id=a;
		}
};

class station{
	private:
		int id,bsize,bfront,brear;
		cargo* b;
	public:
		station(){
			bfront=0;
			brear=0;
		}
		void setsize(int size){
			bsize=size;
			b= new cargo[bsize];
			for(int i=0;i<bsize;++i)b[i].setID(-1);
		}
		void putcargo(cargo c){
			b[brear%bsize]=c;
			++brear;
		}
		cargo takecargo(){
			cargo c=b[bfront%bsize];
			b[bfront%bsize].setID(-1);
			++bfront;
			return c;
		}
		bool isFull(){
			if(((bfront%bsize)==(brear%bsize))&&(b[brear%bsize].getID()!=-1))return true;
			else return false;
		}
		bool isEmpty(){
			if(((bfront%bsize)==(brear%bsize))&&(b[brear%bsize].getID()==-1))return true;
			else return false;
		}
		int getID(){
			return id;
		}
		void setID(int a){
			id=a;
		}
		/*void printb(){
			cout << "station: " << id << "\n";
			for(int i=0;i<bsize;++i)cout << b[i].getID() << "\n";
		}*/
};

class carrier{
	private:
		int min,capacity,top;
		cargo* c;
	public:
		carrier(int a){
			min=0;
			top=-1;
			capacity=a;
			c = new cargo[capacity];
		}
		void unloadcargo(station* s){
			s->putcargo(c[top]);
			--top;
			++min;
		}
		void loadcargo(station* s){
			c[top+1]=s->takecargo();
			++top;
			++min;
		}	
		bool isFull(){
			if(top==capacity-1)return true;
			else return false;
		}
		bool isEmpty(){
			if(top==-1)return true;
			else return false;
		}
		void sendcargo(){
			--top;
			++min;
		}
		int getIDtop(){
			return c[top].getID();
		}
		void nextstation(){
			min+=2;
		}
		int getmin(){
			return min;
		}
		/*int gettop(){
			return top;
		}
		void printc(){
			cout << "carrier: " << "\n";
			for(int i=0;i<capacity;++i)cout << c[i].getID() << "\n";
		}*/
};

int main(){
	/*station* s = new station();
	int bsize,capacity;
	cin >> bsize >> capacity;
	s->setsize(bsize);
	char c;
	cin >> c;
	carrier* r= new carrier(capacity); 
	while(c!='b'){
		if(c=='p'){
			cargo aux;
			int a;
			cin >> a;
		 	aux.setID(a);
		 	s->putcargo(aux);
		 	s->printb();
		}
		if(c=='t'){
			cargo aux=s->takecargo();
			s->printb();
		}
		if(c=='l'){
			r->loadcargo(s);
			s->printb();
			r->printc();
			cout << "top: " << r->gettop() << "\n";
		}
		if(c=='u'){
			r->unloadcargo(s);
			s->printb();
			r->printc();
			cout << "top: " << r->gettop() << "\n";
		}
		cin >> c;
	}*/
	int set;
	cin >> set;
	while(set){
		int nstations,capacity,bsize;
		cin >> nstations >> capacity >> bsize;
		station* s = new station[nstations];
		for(int i=0;i<nstations;++i){
			s[i].setID(i+1);
			s[i].setsize(bsize);
			int qi;
			cin >> qi;
			while(qi){
				int id;
				cin >> id;
				//cout << id;
				cargo aux;
				aux.setID(id);
				s[i].putcargo(aux);
				--qi;
			}
			//cout << s[i].getID() << "\n";
		}

		carrier* c = new carrier(capacity);
		int stationit=0;
		while(true){
			//cout << "idtop: "<<c->getIDtop() << "\n";
			//cout << "station: "<<s[stationit%nstations].getID() << "\n";
			if(!c->isEmpty()){
				if(c->getIDtop()==s[stationit%nstations].getID()){
					c->sendcargo();
					//cout << "send\n";
					//cout << "top: "<<c->gettop() << "\n";
					continue;
				}
				else{
					if(!s[stationit%nstations].isFull()){
						c->unloadcargo(&s[stationit%nstations]);
						//cout << "unload\n";
						continue;
					}	
				}
			}
			while((!c->isFull())&&(!s[stationit%nstations].isEmpty())){
				c->loadcargo(&s[stationit%nstations]);
				//cout << "load\n";
			}	
			if(c->isEmpty()){
				bool q=true;
				for(int i=0;i<nstations;++i)if(!s[i].isEmpty())q=false;
					//cout << "break\n";
				if(q)break;
			}
			c->nextstation();
			++stationit;
		}
		cout << c->getmin() << "\n";
		--set;
	}
	return 0;
}