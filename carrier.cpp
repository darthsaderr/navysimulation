/*
* Sadie Jungers
* implementation for carrier class
*/

#include "carrier.h"
using namespace std;

carrier::carrier():Movable(){
	planecap=0;
	planecur=0;
	maxs=0;
}
//time,id,name,x,y,deployed,planecap,planecur
carrier::carrier(string namex,string idx,int pca, double ms):Movable(namex,idx,ms){
	planecap=pca;
	planecur=0;
}


void carrier::print(){
	cout << name << " " << id << endl;
	cout << "maximum speed: " << maxs << endl;
	cout << "maximum planes: " << planecap << endl;
}


/*
	private:
		int planecap; //plane capacity
		int planecur; //current number of planes
		bool deployed;
		bool wasdeployed;
		double maxs; //max speed
		std::string id;
		std::string name;
		HistoryList histlist;
		Location mov;
		double heading;
		double speed;
*/
