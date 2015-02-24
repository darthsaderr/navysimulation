/*
* Sadie Jungers
* implementation for order class 
*/

#include "order.h"
using namespace std;

Order::Order(){
	t=0;
}
Order::Order(ATime tt){
	t=tt;
}
Order::Order(ATime tt,std::string x){
	t=tt;
	id=x;
}

void Order::printOrder() {
	cout << "Parent Order: " << t;
	cout << " id= " << id << endl;
}
ATime Order::exectime() const {
	return t;
}
string Order::get_id() {
	return id;
}
bool Order::operator==(const Order& o){
	if (t==o.exectime()) return true;
	else return false;
}
bool Order::operator<(const Order& o){
	if(t<o.exectime()) return true;
	else return false;
}
bool Order::operator>(const Order& o){
	if(t>o.exectime()) return true;
	else return false;
}
bool Order::operator!=(const Order& o){
	if(t==o.exectime()) return false;
	else return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////

//CHANGE PLANE ORDER
changePord::changePord():Order(){
	heading=-1;
	speed=-1;
}
changePord::changePord(ATime t,string id,double h,double s,double alt):Order(t,id){ //atime,id,heading,speed,altitude
	heading=h;
	speed=s;
	altitude=alt;
}
bool changePord::Execute(Movable *x,ATime t){
	x->changeord(t,heading,speed,altitude);
	return true;
}

void changePord::printOrder() {
	cout << "Change Aircraft Order: time= " << t;
	cout << " id= " << id << endl;
	cout << "Heading= " << heading;
	cout << " speed= " << speed << endl;
	cout << "Altitude= " << altitude << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////

//CHANGE SHIP ORDER
changeSord::changeSord():Order(){
	heading=-1;
	speed=-1;
}
changeSord::changeSord(ATime t,string id,double h,double s):Order(t,id){ //atime,id,heading,speed
	heading=h;
	speed=s;
}
bool changeSord::Execute(Movable *x,ATime t){
	x->changeord(t,heading,speed,0.0);
	return true;
}

void changeSord::printOrder() {
	cout << "Change Ship Order: time= " << t;
	cout << " id= " << id << endl;
	cout << "Heading= " << heading;
	cout << " speed= " << speed << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////

//LAND PLANE ORDER
landP::landP():Order(){ //constructor
	//shipid="";
}
landP::landP(ATime t,Movable* sid,string id):Order(t,id){ //constructor
	shipid=sid;
}
bool landP::Execute(Movable *x,ATime t){
	fighter* fp=dynamic_cast<fighter*>(x);
	if(fp) fp->landplane(t,shipid);
	return true;
}

void landP::printOrder() {
	cout << "Land Aircraft Order: time= " << t;
	cout << " id= " << id << endl;
	cout << "Land on ship: " << shipid->getID();
}
//////////////////////////////////////////////////////////////////////////////////////////////

//DEPLOY SHIP ORDER
deploySord::deploySord():Order(){
	x=0;
	y=0;
	heading=0;
	speed=0;
}
deploySord::deploySord(ATime t,string id,double xx,double yy,double h,double s):Order(t,id){ 
	x=xx;
	y=yy;
	heading=h;
	speed=s;
}
bool deploySord::Execute(Movable *xx,ATime t){
	xx->deploy(t,x,y,0.0,heading,speed);
	return true;
}

void deploySord::printOrder() {
	cout << "Deploy Ship Order: time= " << t;
	cout << " id= " << id << endl;
	cout << "Heading= " << heading;
	cout << " speed= " << speed << endl;
	cout << "Initial coordinates (" << x << "," << y << ")\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////

//DEPLOY PLANE ORDER
deployPord::deployPord():Order(){
	z=0;
	heading=0;
	speed=0;
}
deployPord::deployPord(ATime t,string id,double h,double s,double zz):Order(t, id){ //time,id,x,y,z,heading,speed
	z=zz;
	heading=h;
	speed=s;
}
bool deployPord::Execute(Movable* x,ATime t) {
	fighter* fp=dynamic_cast<fighter*>(x);
	x->deploy(t,heading,speed,z);
	return true;
}

void deployPord::printOrder() {
	cout << "Deploy Aircraft Order: " << t;
	cout << " id= " << id << endl;
	cout << "Heading= " << heading;
	cout << " speed= " << speed << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////

/* 
StartSim: Day Time
 StopSim: Day Time
 CreateCruiser: Name ID Number of Missiles Max speed
 CreateFighter: Name ID ShipID Maxspeed Maxaltitude Maxbombs
 CreateAirCraftCarrier: Name ID Maxnumberofaircraft Maxspeed
 DeployShip: Day Time ID X Y Heading Speed
 DeployAircraft: Day Time ID Heading Speed Altitude
 ChangeAircraftOrders: Day Time Heading Speed Altitude
 LandAircraft: Day Time ShipID Aircraft ID
 ChangeShipOrders: Day Time ID Heading Speed
*/







