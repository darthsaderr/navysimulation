/*
* Sadie Jungers
* header file for movable class (parent to ships and planes) 
*/
#ifndef MOVABLE_H
#define MOVABLE_H

#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <map>
#include <deque>
#include "atime.h"
#include "location.h"

class Order;
class Movable;
class Location;
typedef std::list<Location> HistoryList;
typedef std::map<std::string,Movable*> NavyMap;
typedef std::deque<Order*> OrderQueue;
const double PI=3.14159265359;
class Movable{
	public:
		Movable();
		Movable(std::string,std::string,double); //name,id,name 
		virtual bool changeord(ATime,double,double,double);//time,heading,speed
		virtual void updatePosition(ATime); 
		bool isDeployed() const;
		bool wasDeployed() const;
		HistoryList* getHistory();	
		void printhistory();
		std::string getID();
		virtual bool deploy(ATime,double,double,double);
		virtual bool deploy(ATime,double,double,double,double,double);
		virtual void  print();
		Location getLocation(); 
		
	protected:
		bool isdeployed;
		bool wasdeployed;
		double maxs; //max speed
		std::string id;
		std::string name;
		HistoryList histlist;
		Location mov; //current location
		double heading;
		double speed;
};

#endif
