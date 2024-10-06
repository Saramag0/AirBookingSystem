#ifndef _RESERVATIONDATABASE_H
#define _RESERVATIONDATABASE_H

#include "Resservation.h"
#include "FlightSchedule.h"
#include "Flight.h"

extern const int discount[8];
// discount[ 0 ]: not used
// discount[ 1 ]: Full Fare Ticket
// discount[ 2 ]: Child Ticket:              25% off of the full fare
// discount[ 3 ]: Infant Ticket:             Free of charge
// discount[ 4 ]: Senior Citizen Ticket:     50% off of the full fare
// discount[ 5 ]: Impaired Ticket:           50% off of the full fare
// discount[ 6 ]: Impaired Companion Ticket: 50% off of the full fare
// discount[ 7 ]: Military Ticket:            5% off of the full fare



class ReservationDataBase {
public:
	ReservationDataBase();
	// input the number of tickets for each ticket type, and assign them to reservation.tickets
	void inputNumTickets(Reservation& reservation);
	bool duplicate(Reservation reservation);  //°»´ú¦P¤@µ§­q²¼¬ö¿ý
	void displayReservation(Reservation reservation,
		Flight flights[], int numFlights);
	void displayReservation(Reservation reservation,
		FlightSchedule flightschedule, int numFlights);
	void saveReservation(const Reservation reservation);
	void loadReservations();
	void setNum(int num);
	int getNum();
	Reservation getreservations(int i);
private:
	int reservationsnum;
	Reservation reservation;
	Reservation reservations[200];
};

#endif