/*
* Sadie Jungers
* implementation for atime.h  
*/
#include <iostream>
#include <ctime>
#include <time.h>
#include "atime.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//constructors
ATime::ATime(){
	m_time=0;
}
ATime::ATime(time_t t){
	m_time=t;
}
ATime::ATime(string date, string time){
	char junk;
	int m,d,y,h,mm,s;
	istringstream ind(date);
	ind >> m >> junk >> d >> junk >> y;
	istringstream inst(time);
	inst >> h >> junk >> mm >> junk >> s;
	struct tm x;
	x.tm_mon=m-1;
	x.tm_mday=d;
	x.tm_year=y-1900;
	x.tm_hour=h;
	x.tm_min=mm;
	x.tm_sec=s;
	if(x.tm_mon>3 && x.tm_mon<11) {
		x.tm_isdst=1;
	} else x.tm_isdst=0;
	m_time=mktime(&x); 
}

string ATime::getSVal() const{ //opposite of constructor
	tm *stp;
	stp=localtime(&m_time);
	ostringstream os;
	os << setfill('0') << setw(2) << stp->tm_mon+1 << "/";
	os << setfill('0') << setw(2) << stp->tm_mday << "/";
	os << setfill('0') << setw(4) << stp->tm_year+1900 << " ";
	os << setfill('0') << setw(2) << stp->tm_hour << ":";
	os << setfill('0') << setw(2) << stp->tm_min << ":";
	os << setfill('0') << setw(2) << stp->tm_sec << " ";
	return os.str();
}

//friend functions
ostream& operator<<(ostream& os, ATime at){ 
	os << at.getSVal();
	return os;
}
ATime operator+(int i, const ATime& a){ 
	ATime temp;
	temp=i+a.m_time;
	return temp;
}

//member functions
bool ATime::operator<(const ATime& a) const{
	return (m_time < a.m_time);
}
bool ATime::operator>(const ATime& a) const{
	return(m_time > a.m_time);
}
bool ATime::operator==(const ATime& a) const{
	return(m_time == a.m_time);
}
bool ATime::operator!=(const ATime& a) const{
	return(m_time != a.m_time);
}
ATime ATime::operator+(const int i) const {
	return(m_time + i);
}
ATime ATime::operator++(){ //preincrementer
	m_time=m_time + 1;
	return m_time;
}
ATime ATime::operator++(int i){ //postincrementer
	ATime old=m_time;
	m_time=m_time + 1;
	return old;
}
ATime& ATime::operator+=(int i) {
	m_time=m_time+i;        
	return *this;
}
int ATime::operator-(const ATime& a) const {
	return(m_time - a.m_time);
}
int ATime::operator-(const int i) const {
	return(m_time - i);
}

/*
* time struct
* #include <time.h>
* struct tm {
*        int tm_sec;     /* seconds after the minute - [0,59] 
*        int tm_min;     /* minutes after the hour - [0,59] 
*        int tm_hour;    /* hours since midnight - [0,23] 
*        int tm_mday;    /* day of the month - [1,31] 
*        int tm_mon;     /* months since January - [0,11] 
*        int tm_year;    /* years since 1900 
*        int tm_wday;    /* days since Sunday - [0,6] 
*        int tm_yday;    /* days since January 1 - [0,365] 
*        int tm_isdst;   /* daylight savings time flag 
*        };
* struct tm* now;
* time_t timevar;
* time(&timevar);
* now = localtime(&timevar); 
* timevar = mktime(now);
* // check out the function   strftime();
*/


