/*
* Sadie Jungers
* header file for all order classes
*/

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "movable.h"
#include "order.h"
#include "carrier.h"
#include "fighter.h"
#include "cruiser.h"
#include "location.h"
#include "atime.h"
#include "SimulationMgr.h"

class Movable;
class Order {
	public:
		Order(); //constructor
		Order(ATime,std::string); //constructor
		Order(ATime); //constructor
		bool operator==(const Order& o);
		bool operator<(const Order& o);
		bool operator>(const Order& o);
		bool operator!=(const Order& o);
		ATime exectime() const;
		std::string get_id();
		virtual bool Execute(Movable*,ATime)=0; //pure virtual
		virtual void printOrder();
	protected:
		ATime t;
		std::string id;
}; 

class changeSord:public Order{
	public:
		changeSord();
		changeSord(ATime,std::string,double,double); //atime,id,heading,speed
		bool Execute(Movable *,ATime);
		void printOrder();
	private:
		double heading;
		double speed;
};

class changePord:public Order{
	public:
		changePord(); //constructor
		changePord(ATime,std::string,double,double,double); //atime,id,heading,speed,altitude
		bool Execute(Movable *,ATime);
		void printOrder();
	private:
		double heading;
		double speed;
		double altitude;
		int bombs;
};

class landP:public Order{
	public:
		landP(); //constructor
		landP(ATime,Movable*,std::string); //constructor
		bool Execute(Movable *,ATime);
		void printOrder();
	private:
		Movable* shipid;
};

class deploySord:public Order{
	public:
		deploySord();
		deploySord(ATime,std::string,double,double,double,double); //time,id,location,heading,speed
		bool Execute(Movable *,ATime);
		void printOrder();
	private:
		double x;
		double y;
		double heading;
		double speed;
};

class deployPord:public Order{
	public:
		deployPord();
		deployPord(ATime,std::string,double,double,double); //time,id,z,heading,speed
		bool Execute(Movable *,ATime);
		void printOrder();
	private:
		double z;
		double heading;
		double speed;
}; 
#endif
		
