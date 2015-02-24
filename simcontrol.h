/*
* Sadie Jungers
* header file for simulation manager class
*/
#ifndef SIMCONTROL_H
#define SIMCONTROL_H

#include <iostream>
#include "carrier.h"
#include "fighter.h"
#include "cruiser.h"
#include "location.h"
#include "atime.h"
#include "movable.h"
#include "order.h"



class SimulationMgr{
	public:
		bool simInit(std::string orderFile);
		void simDoUpdate(ATime);
		ATime getStart() const;
		ATime getStop() const;
		NavyMap* getNavy();
		OrderQueue* sortOrders();
		static bool swap(Order*,Order*);
		void printOrders();
		void printNavy();
		void sendUpdateCmd(ATime);
	private:
		ATime start;
		ATime stop;
		NavyMap navy;
		OrderQueue orq; 
};

#endif
