/*
* Sadie Jungers
* header file for cruiser class
*/
#ifndef CRUISER_H
#define CRUISER_H

#include "movable.h"

class cruiser:public Movable{
	public:
		cruiser();
		cruiser(std::string,std::string,int,double); //name,id,bombcap,max speed
		void print();
	private:
		int bombcap; //bomb capacity
		int bombcur; //current number of bombs
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
