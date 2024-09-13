#include<iostream> 
using namespace std;
class Car{
	bool startEngine;
	public:
		void start(){
			startEngine=true;
			cout<<"Engine started:)"<<endl;
		}
		void derive(){
			if(startEngine){
				cout<<"you are ready to derive:)";
			}
			else{
				cout<<"Can't drive the car";
			}
		}
};
main(){
	Car c;
	c.start();
	c.derive();
}
