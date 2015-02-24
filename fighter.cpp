/*
* Sadie Jungers
* implementation for fighter class
*/

#include "fighter.h"

using namespace std;

fighter::fighter():Movable(){
	bombcap=0;
	bombcur=0;
	islanding=false;
}
//name,id,shipid,deployed,bombcap
fighter::fighter(string namex,string idx,Movable* ship_id,int bcap,double ms):Movable(namex,idx,ms){
	bombcap=bcap;
	bombcur=0;
	ship=ship_id;
	islanding=false;
}
void fighter::print(){
	cout << name << " " << id << endl;
	cout << "maximum speed: " << maxs << endl;
	cout << "maximum bombs: " << bombcap << endl;
	//add printing out historylist?
}
void fighter::updatePosition(ATime ticktock) {
  if(!isdeployed) return;
  if(islanding) this->landingmath(ticktock);
	double dist,dx,dy,angle,radangle,x,y;
	int time;
	//cout << "Updating Position.\n";
	mov.getXYZ(x,y,z);
	time=ticktock-mov.getTime();
	//cout << "time is: " << time << endl;
	dist=time*speed/3600.0;
	radangle=heading*PI/180;
	dx=dist*(sin(radangle));
	dy=dist*(cos(radangle));
	x+=dx;
	y+=dy;
	mov=Location(ticktock,x,y,z);
	/*if(id=="ft3002"){
		cout << id << " new location is: " << mov.getXYZ() << endl;
	}*/
	histlist.push_back(mov);
}

bool fighter::deploy(ATime t,double h,double s,double zz){ 
	isdeployed=true;
	wasdeployed=true;
	mov=ship->getLocation();
	histlist.push_back(mov);
	heading=h;
	speed=s;
	mov.setZ(zz);
	//bombcur=b;
	islanding=false;
	return true;
}
bool fighter::changeord(ATime t,double h,double s,double zz){//time,id,heading,speed,altitude
	if(h!=-1) heading=h;
	if(s!=-1) speed=s;
	if(zz!=-1) mov.setZ(zz);
}
void fighter::landplane(ATime t,Movable* lship) { //lship=landing ship
	islanding=true;
	ship=lship;
	this->updatePosition(t);
	this->landingmath(t);
}

void fighter::landingmath(ATime t){
	double dist,dx,dy,angle,radangle,x,y,hyp2,hyp;
	int time;
	Location landingzone;
	landingzone=ship->getLocation();
	mov.getXYZ(x,y,z);
	time=t-mov.getTime();
	dist=time*speed/3600.0;
	dx=(landingzone.getX())-(mov.getX());
	//cout << "dx: " << dx << endl;
	dy=(landingzone.getY())-(mov.getY());
	//cout << "dy: " << dy << endl;
	if (dx==0 && dy>0) {
		heading=0;
	}
	else if (dx==0 && dy<0){
		heading=180;
	}
	else {
	heading=atan(fabs(dy/dx));
	heading=heading*180.0/PI;
	}
	//cout << "heading: " << heading << endl;
	hyp2=dx*dx+dy*dy;
	hyp=sqrt(hyp2);
	//cout << "dist: " << dist << endl;
	//cout << "hyp2: " << hyp2 << endl;
	//cout << "hyp: " << hyp << endl;
	if (dx>0 && dy>0){//+dx,+dy
		heading=(90-heading);
	}
	if (dx>0 && dy<0) { //+dx,-dy
		heading=(90+heading);
	}
	if (dx<0 && dy<0) {//-dx,-dy
		heading=(270-heading);
	}
	if (dx<0 && dy>0) { //-dx,+dy
		heading=(270+heading);
	} 
	if(hyp<=dist){
		islanding=false;
		isdeployed=false;
		histlist.push_back(ship->getLocation());
	}
}

/*
private:
		int bombcap; //bomb capacity
		int bombcur; //current number of bombs
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
