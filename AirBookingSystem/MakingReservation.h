#ifndef _MAKINGRESERVATION_H
#define _MAKINGRESERVATION_H

#include <string>
#include "FlightSchedule.h"
#include "ReservationDataBase.h"
using namespace std;

class MakingReservation {
public:
	MakingReservation(ReservationDataBase reservationdatabase, FlightSchedule flightschedule);
	// choose arrival airport by input its code, and assign the code to arrivalAirport
	void chooseArrivalAirport(int departureAirport, int arrivalAirport);
	void execute();
	ReservationDataBase reservationdatabase;
	FlightSchedule flightschedule;
};

#endif