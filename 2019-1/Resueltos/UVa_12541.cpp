#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class person{
	public:
		string name;
		int day;
		int month;
		int year;
		person(string name,int day,int month,int year){
			this->name=name;
			this->day=day;
			this->month=month;
			this->year=year;
		}
		void change(string name,int day,int month,int year){
			this->name=name;
			this->day=day;
			this->month=month;
			this->year=year;
		}
		bool isOlder(int day,int month,int year){
			if(this->year>year)return false;
			else if(this->year==year){
				if(this->month>month)return false;
				else if(this->month==month){
					if(this->day>day)return false;
					else return true;
					
				}
				else return true;
			}
			else return true;
		}
};

int main(){
	int n;
	cin >> n;
	string name;
	int day,month,year;
	cin>> name >> day >> month >> year;
	person* oldest = new person(name,day,month,year);
	person* youngest = new person(name,day,month,year);
	--n;
	while(n){
		cin >> name >> day >> month >> year;
		if(!oldest->isOlder(day,month,year))oldest->change(name,day,month,year);
		if(youngest->isOlder(day,month,year))youngest->change(name,day,month,year);
		--n;
	}
	cout << youngest->name << "\n" << oldest->name << "\n";
	return 0;
}