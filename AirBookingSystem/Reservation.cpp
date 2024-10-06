#include "Resservation.h"
#include <iostream>
#include <string>
#include <vector>

Reservation::Reservation(  string flightNoValue, string idValue,
	string nameValue, string mobileValue, string dateValue  ) 
{
	for (int i = 0; i < 8; i++) {
		if (i < flightNoValue.size())
			flightNo[i] = flightNoValue[i];
		else
			flightNo[i] = '\0';
	}
	for (int i = 0; i < 12; i++) {
		if (i < idValue.size())
			id[i] = idValue[i];
		else
			id[i] = '\0';
	}
	for (int i = 0; i < 8; i++) {
		if (i < nameValue.size())
			name[i] = nameValue[i];
		else
			name[i] = '\0';
	}
	for (int i = 0; i < 12; i++) {
		if (i < mobileValue.size())
			mobile[i] = mobileValue[i];
		else
			mobile[i] = '\0';
	}
	for (int i = 0; i < 12; i++) {
		if (i < dateValue.size())
			date[i] = dateValue[i];
		else
			date[i] = '\0';
	}
}

void Reservation::setFlightNo(string flightNoValue)
{
	for (int i = 0; i < 8; i++) {
		if (i < flightNoValue.size())
			flightNo[i] = flightNoValue[i];
		else
			flightNo[i] = '\0';
	}
}

void Reservation::setIdValue(string idValue)
{
	for (int i = 0; i < 12; i++) {
		if (i < idValue.size())
			id[i] = idValue[i];
		else
			id[i] = '\0';
	}
}

void Reservation::setNameValue(string nameValue)
{
	for (int i = 0; i < 8; i++) {
		if (i < nameValue.size())
			name[i] = nameValue[i];
		else
			name[i] = '\0';
	}
}

void Reservation::setMobileValue(string mobileValue) 
{
	for (int i = 0; i < 12; i++) {
		if (i < mobileValue.size())
			mobile[i] = mobileValue[i];
		else
			mobile[i] = '\0';
	}
}

void Reservation::setDateValue(string dateValue)
{
	for (int i = 0; i < 12; i++) {
		if (i < dateValue.size())
			date[i] = dateValue[i];
		else
			date[i] = '\0';
	}
}

void Reservation::setTicket(int i, int number)
{
	tickets[i] = number;
}

string Reservation::getFlightNo()
{
	return flightNo;
}

string Reservation::getIdValue() 
{
	return id;
}
string Reservation::getNameValue() 
{
	return name;
}
string Reservation::getMobileValue() 
{
	return mobile;
}
string Reservation::getDateValue() 
{
	return date;
}
int Reservation::getTicket(int i)
{
	return tickets[i];
}
