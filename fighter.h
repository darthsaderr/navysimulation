/*
* Sadie Jungers
* header file for fighter plane class
*/
#ifndef FIGHTER_H
#define FIGHTER_H

#include "movable.h"

class carrier;
class fighter:public Movable{
	public:
		fighter();
		fighter(std::string,std::string,Movable*,int,double); //id,name,shipid,max speed, max bombs
		void updatePosition(ATime); //pure virtual
		void landplane(ATime,Movable*); //time,ship id
		void print();
		bool deploy(ATime,double,double,double); //time,x,y,z,heading,speed,bombcur
		bool changeord(ATime,double,double,double);//time,id,heading,speed,alt
		
	private:
		int bombcap; //bomb capacity
		int bombcur; //current number of bombs
		double z; //altitude
		Movable* ship;
		bool islanding;
		void landingmath(ATime);
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
