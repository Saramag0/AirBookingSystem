#include "FlightSchedule.h"
#include "Resservation.h"
#include "Flight.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

FlightSchedule::FlightSchedule()
{
    
}

void FlightSchedule::chooseArrivalAirport(int departureAirport, int& arrivalAirport)
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

void FlightSchedule::loadFlightSchedules() 
{
    fstream infile("Flight Schedule.dat", ios::in | ios::binary);
    infile.seekg(0, ios::end);
    FlightSchedule::numFlights = static_cast<int>(infile.tellg()) / sizeof(Flight);

    infile.seekg(0, ios::beg);
    for (int i = 0; i < numFlights; i++)
    {
        infile.read(reinterpret_cast<char*>(&flights[i]), sizeof(Flight));
    }
    infile.close();
}


void FlightSchedule::loadFlightSchedules(Flight flights[], int& numFlights,
	int departureAirport, int arrivalAirport)
{
    int num = 0;

    loadFlightSchedules();

    for (int i = 0; i < 108; i++)
    {
        if (FlightSchedule::flights[i].getDepartureAirport() == departureAirport && 
            FlightSchedule::flights[i].getArrivalAirport() == arrivalAirport)
        {
            numFlights++;
            flights[numFlights] = FlightSchedule::flights[i];
        }
    }
}

void FlightSchedule::displayFlights(Flight flights[], int numFlights,
	int departureAirport, int arrivalAirport, string date)
{
    cout << airportName[ departureAirport ] << " to " << airportName[ arrivalAirport ]
        << " / Depart date: " << date << ".\n\n";
   cout << "Flight   Departure   Arrival   Fare\n";

   for( int i = 1; i <= numFlights; i++ )
      cout << setw( 6 )  << flights[ i ].getFlightNo()
           << setw( 12 ) << flights[ i ].getDepartureTime()
           << setw( 10 ) << flights[ i ].getArrivalTime()
           << setw( 7 )  << fullFare[ departureAirport ][ arrivalAirport ] << endl;
}

// choose a flight by input its number, and assign the number to reservation.flightNo
void FlightSchedule::chooseFlight(Reservation& reservation, Flight flights[], int numFlights)
{
    bool exist = true;
    while (exist) {
        string flightnumber;
        cout << "Flight number: ";
        cin >> flightnumber;
        reservation.setFlightNo(flightnumber);
        for (int j = 0; j <= numFlights; j++)
        {
            if (reservation.getFlightNo() == flights[j].getFlightNo())  //當輸入的航班存在，則跳出迴圈
            {
                exist = false;
            }
        }
    }
}

Flight FlightSchedule::getflights(int i)
{
    return flights[i];
}