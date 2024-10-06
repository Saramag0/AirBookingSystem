#include "Flight.h"
#include <iostream>
#include <iomanip>
#include <string>

Flight::Flight(string flightNoValue, int departureAirportValue, int arrivalAirportValue,
	string departureTimeValue, string arrivalTimeValue)
{
	for (int i = 0; i < flightNoValue.size(); i++) {
		flightNo[i] = flightNoValue[i];
	}
	Flight::departureAirport = departureAirportValue;
	Flight::arrivalAirport = arrivalAirportValue;
	for (int i = 0; i < departureTimeValue.size(); i++) {
		departureTime[i] = departureTimeValue[i];
	}
	for (int i = 0; i < arrivalTimeValue.size(); i++) {
		arrivalTime[i] = arrivalTimeValue[i];
	}
}
void Flight::setFlightNo(string flightNoValue) 
{
	for (int i = 0; i < flightNoValue.size(); i++) {
		flightNo[i] = flightNoValue[i];
	}
}
void Flight::setDepartureAirport(int departureAirportValue)
{
	Flight::departureAirport = departureAirportValue;
}
void Flight::setArrivalAirport(int arrivalAirportValue) 
{
	Flight::arrivalAirport = arrivalAirportValue;
}
void Flight::setDepartureTime(string departureTimeValue)
{
	for (int i = 0; i < departureTimeValue.size(); i++) {
		departureTime[i] = departureTimeValue[i];
	}
}
void Flight::setArrivalTime(string arrivalTimeValue)
{
	for (int i = 0; i < arrivalTimeValue.size(); i++) {
		arrivalTime[i] = arrivalTimeValue[i];
	}
}
string Flight::getFlightNo()
{
	return flightNo;
}
int Flight::getDepartureAirport()
{
	return departureAirport;
}
int Flight::getArrivalAirport()
{
	return arrivalAirport;
}
string Flight::getDepartureTime()
{
	return departureTime;
}
string Flight::getArrivalTime()
{
	return arrivalTime;
}

void Flight::display(string date)
{
	std::cout << setw(6) << flightNo
		<< setw(12) << airportName[departureAirport][arrivalAirport]
		<< setw(12) << date
		<< setw(12) << departureTime
		<< setw(10) << arrivalTime
		<< setw(7) << fullFare[departureAirport][arrivalAirport] << endl;
}