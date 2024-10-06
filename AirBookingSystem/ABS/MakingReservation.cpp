#include "FlightSchedule.h"
#include "Flight.h"
#include "MakingReservation.h"
#include "ReservationDataBase.h"
#include "Resservation.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

MakingReservation::MakingReservation(ReservationDataBase reservationdatabase, FlightSchedule flightschedule)
    :reservationdatabase(reservationdatabase), flightschedule(flightschedule)
{
}

void MakingReservation::chooseArrivalAirport(int departureAirport, int arrivalAirport)
{
    do {
        cout << "Arrival airport: " << endl;
        for (int i = 1; i <= 11; i++)
        {
            if (fullFare[departureAirport][i] != 0) //不等於0 代表有班次
            {
                cout << i << ". " << airportName[i] << endl;
            }

        }
        cout << "? ";
        cin >> arrivalAirport;
    } while (fullFare[departureAirport][arrivalAirport] == 0); //如果沒有班次就重新輸入
}

void MakingReservation::execute()
{
    FlightSchedule fs;
    ReservationDataBase rdb;

    int departureAirport = 0;
    do {
        cout << "\nDeparture airport:\n";
        for (int i = 1; i <= 11; i++)
            cout << setw(2) << i << ". " << airportName[i] << endl;
        cout << "? ";

        cin >> departureAirport;
    } while (departureAirport < 1 || departureAirport > 11);

    int arrivalAirport = 0;
    // choose arrival airport by input its code, and assign the code to arrivalAirport
    fs.chooseArrivalAirport( departureAirport, arrivalAirport );

    Reservation reservation;
    string datevalue;
    cout << "\nDeparture date (yyyy/mm/dd): ";
    cin >> datevalue;
    reservation.setDateValue(datevalue);
    cout << endl;

    Flight flights[100];
    int numFlights = 0;

    // load all flights from departureAirport to arrivalAirport,
    // and put them into the array flights
    fs.loadFlightSchedules(flights, numFlights, departureAirport, arrivalAirport);

    // display all flights from departureAirport to arrivalAirport
    fs.displayFlights(flights, numFlights, departureAirport, arrivalAirport, reservation.getDateValue());

    // choose a flight by input its number, and assign the number to reservation.flightNo
    fs.chooseFlight(reservation, flights, numFlights);

    // input the number of tickets for each ticket type,
    // and assign them to reservation.tickets
    rdb.inputNumTickets(reservation);

    int totalNumTickets = 0;
    for (int i = 1; i < 8; i++)
        totalNumTickets += reservation.getTicket(i);
    if (totalNumTickets == 0)
    {
        cout << "Your booking could not be completed!\n";
        return;
    }

    rdb.displayReservation(reservation, flights, numFlights);

    string id;
    cout << "\nID number: ";
    cin >> id;
    reservation.setIdValue(id);

    // check if there is a record, x, of Reservations.dat such that
    // x.flightNo == reservation.flightNo, x.id == reservation.id and
    // x.date == reservation.date
    if (rdb.duplicate(reservation))
        return;

    string name, mobile;
    cout << "\nName: ";
    cin >> name;
    reservation.setNameValue(name);
    cout << "\nMobile: ";
    cin >> mobile;
    reservation.setMobileValue(mobile);

    // append reservation to the end of Reservations.dat
    rdb.saveReservation(reservation);

    cout << "\nBooking completed!\n";
}