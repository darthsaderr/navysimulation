/*
* Sadie Jungers
* implementation for location class
*/

#include "location.h"
using namespace std;

Location::Location(){
	t=0; //ATime
	x=0.0;
	y=0.0;
	z=0.0;
}
Location::Location(ATime tt){
	t=tt;
	x=0.0;
	y=0.0;
	z=0.0;
}
Location::Location(ATime tt,double xx,double yy,double zz){
	t=tt;
	x=xx;
	y=yy;
	z=zz;
}
/*Location Location::operator=(Location& loc){
	t=loc.t;
	x=loc.x;
	y=loc.y;
	z=loc.z;
	return *this;
}*/
void Location::printL(){
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << t << " ";
	cout << "x= " << x << " ";
	cout << "y= " << y << " ";
	cout << "z= " << z;
}
ATime Location::getTime(){
	return t;
}

Location Location::getXYZ(){
	return *this;
}
void Location::setZ(double alt){
	z=alt;
}
double Location::getX(){
	return x;
}
double Location::getY(){
	return y;
}
double Location::getZ(){
	return z;
}
void Location::getXYZ(double& xx,double& yy,double& zz){
	xx=x;
	yy=y;
	zz=z;
}
Location Location::makeXYZ(ATime tt,double xx,double yy,double zz) {
	Location temp(tt,xx,yy,zz);
	return temp;
}

ostream& operator<<(ostream& os, const Location loc){
	os.setf(ios::fixed);
	os.precision(2);
	os <<  loc.t << " ";
	os << loc.x << " ";
	os << loc.y << " ";
	os << loc.z;
	return os;
}



