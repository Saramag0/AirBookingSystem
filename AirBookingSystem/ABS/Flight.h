#ifndef _FLIGHT_H
#define _FLIGHT_H

#include <string>
using namespace std;

extern const char airportName[12][12];
extern const int fullFare[12][12];

class Flight {
public:
	Flight(string flightNoValue = "", int departureAirportValue = 0, int arrivalAirportValue = 0,
		string departureTimeValue = "", string arrivalTimeValue = "");
	void setFlightNo(string flightNoValue);
	void setDepartureAirport(int departureAirportValue);
	void setArrivalAirport(int arrivalAirportValue);
	void setDepartureTime(string departureTimeValue);
	void setArrivalTime(string arrivalTimeValue);
	string getFlightNo();
	int getDepartureAirport();
	int getArrivalAirport();
	string getDepartureTime();
	string getArrivalTime();

	void display(string date);

private:
	char flightNo[8];	// Flight number
	int departureAirport;	// Departure airport code
	int arrivalAirport;	// Arrival airport code
	char departureTime[8];	// Departure time
	char arrivalTime[8];	// Arrival time
};
#endif