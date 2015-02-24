/*
* Sadie Jungers
* header file for aircraft carrier class
*/
#ifndef CARRIER_H
#define CARRIER_H

#include "movable.h"

class carrier:public Movable{
	public:
		carrier();
		carrier(std::string,std::string,int,double); //id,name,max speed,max planes
		void print(); 
		
	private:
		int planecap; //plane capacity
		int planecur; //current number of planes
		/*
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
};

#endif
