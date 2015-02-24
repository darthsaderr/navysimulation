/*
* Sadie Jungers
* implementation for SimulationMgr class
*/

#include "SimulationMgr.h"
#include <sstream>
#include <string>
#include <fstream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef std::map<std::string,Movable*> NavyMap;
typedef std::deque<Order*> OrderQueue;

bool SimulationMgr::simInit(string orderFile){
	string s;
	ifstream inFile;
	inFile.open(orderFile.c_str());
	if(inFile.fail()){
		cout << "Order file could not be opened.\n";
		return 1;
	}
	while (!inFile.eof()){
		getline(inFile,s); 
		cout << s << endl;
		if (s[0]!='#' && s[0]!=' '){
			string opcode;
			istringstream is(s);
			//cout << "istringstream created.\n";
			is >> opcode;
			//cout << opcode << endl;
			if(opcode=="StartSim"){
				string d,t;
				if(is >> d >> t) {
					ATime tmp(d,t);
					start=tmp;
				}
			} else if(opcode=="StopSim"){
				string d,t;
				if(is >> d >> t) {
					ATime tmp(d,t);
					stop=tmp;
				}
			} else if(opcode=="CreateCruiser") {
				string n,id;
				int m;
				double smax;
				//cout << "creating cruiser\n";
				if(is >> n >> id >> m >> smax){
					cruiser *tc= new cruiser(n,id,m,smax);
					navy[id]=tc;
				}
			} else if(opcode=="CreateFighter"){
				string n,id,sid;
				int b;
				double smax;
				if(is >> n >> id >> sid >> smax >> b){
					Movable* shid=navy[sid];
					fighter *fc= new fighter(n,id,shid,smax,b);
					navy[id]=fc;
				}
			} else if(opcode=="CreateAircraftCarrier"){
				string n,id;
				int p;
				double smax;
				if(is >> n >> id >> p >> smax){
					carrier *ac= new carrier(n,id,p,smax);
					navy[id]=ac;
				}
			} else if(opcode=="DeployShip"){
				string n,id,d,t;
				double x,y,h,s;
				if (is >> d >> t >> id >> x >> y >> h >> s){
					ATime at(d,t);
					//Movable* idp=navy[id];
					Order *ds= new deploySord(at,id,x,y,h,s);
					orq.push_back(ds);
				}
			} else if(opcode=="DeployAircraft"){
				string n,id,d,t;
				double x,y,z,h,s;
				if(is >> d >> t >> id >> h >> s >> z){
					ATime at(d,t);
					//Movable* idp=navy[id];
					Order *da= new deployPord(at,id,h,s,z);
					orq.push_back(da);
				}
			} else if(opcode=="ChangeAircraftOrder"){
				string n,id,d,t;
				double z,h,s;
				if(is >> d >> t >> id >> h >> s >> z){
					ATime at(d,t);
					//Movable* idp=navy[id];
					Order *cao= new changePord(at,id,h,s,z);
					orq.push_back(cao);
				}
			} else if(opcode=="ChangeShipOrder"){
				string n,id,d,t;
				double h,s;
				if(is >> d >> t >> id >> h >> s){
					ATime at(d,t);
					//Movable* idp=navy[id];
					Order *cso= new changeSord(at,id,h,s);
					orq.push_back(cso);
				}
			} else if(opcode=="LandAircraft"){
				string pid,sid,d,t;
				if(is >> d >> t >> sid >> pid){
					ATime at(d,t);
					Movable* ids=navy[sid];
					Order *lp= new landP(at,ids,pid);
					orq.push_back(lp);
				}
			}
		}
	}
	return true;
}
static bool swap(Order* a,Order* b){
	return (*a < *b);
}
OrderQueue* SimulationMgr::sortOrders() {
	sort(orq.begin(),orq.end(),swap);
}

NavyMap* SimulationMgr::getNavy() {
	return &navy;
}
void SimulationMgr::printOrders() {
	OrderQueue::iterator n;
	for(n=orq.begin(); n!=orq.end(); n++){
		(*n)->printOrder();
	}
}
void SimulationMgr::printNavy() {
	NavyMap::iterator nm;
	for(nm=navy.begin(); nm!=navy.end(); nm++) {
		(nm->second)->print();
	}
}
void SimulationMgr::simDoUpdate(ATime ticktock) {
	Order* oP;
  NavyMap::iterator nmi;

  while (orq.size()) {
      oP = orq.front();
      if (oP->exectime() > ticktock) break;
      orq.pop_front();

      nmi = navy.find(oP->get_id());

      if (nmi != navy.end()) {
              oP->Execute(nmi->second,ticktock);
      }
      delete oP;
  }
  sendUpdateCmd(ticktock);
}

void SimulationMgr::sendUpdateCmd(ATime t) {
	NavyMap::iterator mi;
	for (mi = navy.begin(); mi != navy.end(); mi++) {
		(mi->second)->updatePosition(t);
	}
}

ATime SimulationMgr::getStart() const {
	return start;
}
ATime SimulationMgr::getStop() const {
	return stop;
}


/*


	ATime SimTime = start;
	time_t simlength = (stop - start)/60;   // minutes
	Order* op;
	NavyMap::iterator nmi;
	for (i = 0; i < simlength; i++) {
		while (m_orders.size()) {
			op = m_orders.front();
			if (op->exectime() < SimTime) break;
			m_orders.pop_front();
			nmi = navy.find(op->get_id());
			if (nmi != navy.end()) {
				op->Execute(nmi->second,SimTime);
			}
		delete oP;
	}
	sendUpdateCmd(SimTime);
	SimTime += 60;
	}
*/
