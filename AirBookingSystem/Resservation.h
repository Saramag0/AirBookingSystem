#ifndef _RESERVATION_H
#define _RESERVATION_H

#include "Flight.h"

class Reservation {
public:
	Reservation(string flightNoValue = "",string idValue = "",
				string nameValue = "",string mobileValue = "",string dateValue = "");

	void setFlightNo(string flightNoValue);
	void setIdValue(string idValue);
	void setNameValue(string nameValue);
	void setMobileValue(string mobileValue);
	void setDateValue(string dateValue);
	void setTicket(int i,int number);
	string getFlightNo();
	string getIdValue();
	string getNameValue();
	string getMobileValue();
	string getDateValue();
	int getTicket(int i);

private:
	char flightNo[8];	// Flight number
	char id[12];	// ID number
	char name[8];	// Name
	char mobile[12];	// Mobile phone number
	char date[12];	// Departure date
	int tickets[8];
	// tickets[ 0 ]: not used
	// tickets[ 1 ]: number of full fare tickets
	// tickets[ 2 ]: number of child tickets
	// tickets[ 3 ]: number of infant tickets
	// tickets[ 4 ]: number of senior citizen tickets
	// tickets[ 5 ]: number of impaired tickets
	// tickets[ 6 ]: number of impaired companion tickets
	// tickets[ 7 ]: number of military tickets

};
#endif