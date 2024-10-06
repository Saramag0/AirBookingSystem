#ifndef _FLIGHTSCHEDULE_H
#define _FLIGHTSCHEDULE_H

#include <string>
#include "Flight.h"
#include "Resservation.h"
using namespace std;

extern const char airportName[12][12];
extern const int fullFare[12][12];

class FlightSchedule {
private:
	Flight flights[200]{};
	int numFlights = 0;
public:
	
	FlightSchedule();
	// choose arrival airport by input its code, and assign the code to arrivalAirport
	void chooseArrivalAirport(int departureAirport, int& arrivalAirport);
	// load all flights from Flight Schedule.dat and put them into the array flights
	void loadFlightSchedules();
	// load all flights from departureAirport to arrivalAirport,
	// and put them into the array flights
	void loadFlightSchedules(Flight flights[], int& numFlights,
		int departureAirport, int arrivalAirport);
	// display all flights from departureAirport to arrivalAirport
	void displayFlights(Flight flights[], int numFlights,
		int departureAirport, int arrivalAirport, string date);
	void chooseFlight(Reservation& reservation, Flight flights[], int numFlights);

	Flight getflights(int i);
};


#endif