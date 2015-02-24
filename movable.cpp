/*
* Sadie Jungers
* implementation for movable class
*/

#include "movable.h"
#include <math.h>
using namespace std;

Movable::Movable(){
	isdeployed=false;
	wasdeployed=false;
	id="unidentified";
	name="unnamed";
	//histlist?
}

Movable::Movable(string namex,string idx,double maxspeed){ 
	id=idx;
	name=namex;
	maxs=maxspeed;
	
	isdeployed=false;
	wasdeployed=false;
	
}
bool Movable::deploy(ATime t,double xx,double yy,double zz,double h,double s) { //time,x,y,z,h,s
	isdeployed=true;
	wasdeployed=true;
	mov=Location(t,xx,yy,zz);
	//histlist.push_back(mov);
	heading=h;
	speed=s;
	return true;
}
bool Movable::deploy(ATime,double,double,double){}
bool Movable::changeord(ATime t,double h,double s,double zz){//time,heading,speed
	if(h!=-1) heading=h;
	if(s!=-1) speed=s;
	return true;
}
void Movable::print(){
	cout << "Movable " << name << " " << id << endl;
	if (isdeployed) {
		cout << "This vessel is deployed.\n";
	} else {
		cout << "This vessel is not deployed.\n";
	}
	cout << "Heading is " << heading << endl;
	cout << "Speed is " << speed << endl;
	cout << "Location History: \n";
	//this->printhistory();
}

void Movable::printhistory() {
	HistoryList::iterator i;
	for (i=histlist.begin(); i!=histlist.end(); i++){
		i->printL();
		cout << endl;
	}
}
Location Movable::getLocation(){
	mov.getXYZ();
	return mov;
}

void Movable::updatePosition(ATime ticktock) {
	if(!isdeployed) return;
	else{
	double dist,dx,dy,z=0.0,angle,radangle,x,y;
	int time;
	//cout << "Updating Position.\n";
	mov.getXYZ(x,y,z);
	//cout << "mov is " << mov << endl;
	//ATime then=mov.getTime();
	time=ticktock-mov.getTime();
	//cout << "simtime: " << ticktock << endl;
	//cout << "then: " << then << endl;
	//cout << "time is: " << time << endl;
	dist=time*speed/3600.0;
	//cout << "distance traveled: " << dist << endl;
	radangle=heading*PI/180;
	//cout << "heading is " << heading << endl;
	//cout << "angle in radians is " << radangle << endl;
	dx=dist*(sin(radangle));
	//cout << "change in x is " << dx << endl;
	dy=dist*(cos(radangle));
	//cout << "change in y is " << dy << endl;
	x+=dx;
	y+=dy;
	mov=Location(ticktock,x,y,z);
	//cout << "m= " << m << endl;
	/*if (id=="ca2001"){
		cout << id << " new location is: " << mov.getXYZ() << endl;
	}*/ 
	histlist.push_back(mov);
	//this->printhistory();
	}
}

bool Movable::isDeployed() const{
	return isdeployed;
}

bool Movable::wasDeployed() const{
	return wasdeployed;
}
HistoryList* Movable::getHistory() {
	return &histlist;
}

string Movable::getID() {
	return id;
}
