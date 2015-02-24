#ifndef LOCATION_H
#define LOCATION_H

#include "atime.h"

class Location {
	friend std::ostream& operator<<(std::ostream&, const Location);
	public:
		Location();
		Location(ATime);
		Location(ATime,double,double,double);
		//Location operator=(Location&);
		
		void printL();
		ATime getTime();
		Location getXYZ();
		double getX();
		double getY();
		double getZ();
		void setZ(double);
		void getXYZ(double&,double&,double&);
		Location makeXYZ(ATime,double,double,double);
	private:
		double x;
		double y;
		double z;
		ATime t;
};	
#endif
