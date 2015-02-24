/*
* Sadie Jungers
* implementation for cruiser class
*/

#include "cruiser.h"
using namespace std;

cruiser::cruiser():Movable(){
	bombcap=0;
	bombcur=0;
}
//time,id,name,x,y,bombcap,bombcur
cruiser::cruiser(string namex,string idx,int bcap,double ms):Movable(namex,idx,ms){
	bombcap=bcap;
	bombcur=0;
}


void cruiser::print(){
	cout << name << " " << id << endl;
	cout << "maximum speed: " << maxs << endl;
	cout << "maximum missiles: " << bombcap << endl;
}


/*
private:
		int bombcap; //bomb capacity
		int bombcur; //current number of bombs
		bool deployed;}		bool wasdeployed;
		double maxs; //max speed
		std::string id;
		std::string name;
		HistoryList histlist;
		Location mov;
		double heading;
		double speed;
*/
