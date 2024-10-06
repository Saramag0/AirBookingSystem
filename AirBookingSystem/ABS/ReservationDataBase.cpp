#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

#include "ReservationDataBase.h"
#include "Resservation.h"
#include "Flight.h"

ReservationDataBase::ReservationDataBase()
{
    
}
// input the number of tickets for each ticket type, and assign them to reservation.tickets
void ReservationDataBase::inputNumTickets(Reservation& reservation)
{
    int ticketsnumber = 0;
    do {
        cout << "\nNumber of infant tickets (0 ~ 4): ";
        cin >> ticketsnumber;
        reservation.setTicket(3, ticketsnumber);
    } while (reservation.getTicket(3) < 0 || reservation.getTicket(3) > 4);

    int numTickets = 0;
    int numAdults = 0;
    do
    {
        numTickets = 0;

        cout << "\nNumber of full fare tickets (0 ~ 4): ";
        cin >> ticketsnumber;
        reservation.setTicket(1, ticketsnumber);
        numTickets += reservation.getTicket(1);

        cout << "\nNumber of child tickets (0 ~ 4): ";
        cin >> ticketsnumber;
        reservation.setTicket(2, ticketsnumber);
        numTickets += reservation.getTicket(2);

        cout << "\nNumber of senior citizen tickets (0 ~ 4): ";
        cin >> ticketsnumber;
        reservation.setTicket(4, ticketsnumber);
        numTickets += reservation.getTicket(4);

        cout << "\nNumber of impaired tickets (0 ~ 4): ";
        cin >> ticketsnumber;
        reservation.setTicket(5, ticketsnumber);
        numTickets += reservation.getTicket(5);

        cout << "\nNumber of impaired companion tickets (0 ~ 4): ";
        cin >> ticketsnumber;
        reservation.setTicket(6, ticketsnumber);
        numTickets += reservation.getTicket(6);

        cout << "\nNumber of military tickets (0 ~ 4): ";
        cin >> ticketsnumber;
        reservation.setTicket(7, ticketsnumber);
        numTickets += reservation.getTicket(7);

        numAdults = reservation.getTicket(1) + reservation.getTicket(4) +
            reservation.getTicket(5) + reservation.getTicket(6) +
            reservation.getTicket(7);

        if (numTickets > 4)
            cout << "\nThis booking system accepts a maximum of 4 passengers"
            << "( including children ) per booking.\n"
            << "If there are more than 4 passengers, please make multiple bookings.\n";
        else if (numAdults < reservation.getTicket(3))
            cout << "\nEach infant must always be accompanied by at least one adult.\n";

    } while (numTickets > 4 || numAdults < reservation.getTicket(3));

    cout << endl;
}
bool ReservationDataBase::duplicate(Reservation reservation)  //°»´ú¦P¤@µ§­q²¼¬ö¿ý
{
    ifstream inFile("Reservations.dat", ios::in | ios::binary);
    inFile.seekg(0, ios::end);
    int num = static_cast<int>(inFile.tellg()) / sizeof(Reservation);
    inFile.seekg(0, ios::beg);

    for (int i = 0; i < num; i++)
    {
        Reservation x;
        inFile.read(reinterpret_cast<char*>(&x), sizeof(Reservation));
        if (x.getFlightNo() == reservation.getFlightNo() && x.getIdValue() == reservation.getIdValue() && x.getDateValue() == reservation.getDateValue()) {
            return true;
        }
    }
    return false;
    inFile.close();
}
void ReservationDataBase::displayReservation(Reservation reservation,
	Flight flights[], int numFlights)
{
    int k;
    for (k = 1; k <= numFlights; k++)
        if (reservation.getFlightNo() == flights[k].getFlightNo())
            break;

    cout << "Ticket information:\n\n";
    cout << "Date: " << reservation.getDateValue() << endl;
    cout << "Flight: B7-" << reservation.getFlightNo() << endl << endl;

    int departureAirport = flights[k].getDepartureAirport();
    int arrivalAirport = flights[k].getArrivalAirport();

    cout << setw(9) << right << airportName[departureAirport] << " -> "
        << setw(9) << left << airportName[arrivalAirport] << endl;

    cout << setw(9) << right << flights[k].getDepartureTime() << "    ";
    cout << setw(9) << left << flights[k].getArrivalTime() << endl << endl;

    char ticketType[8][24] = { "", "Full Fare", "Child Fare", "Infant Fare",
                                       "Senior Citizen Fare",     "Impaired Fare",
                                       "Impaired Companion Fare", "Military Fare" };

    int total = 0;
    int fare;
    for (int i = 1; i <= 7; i++)
        if (reservation.getTicket(i) > 0)
        {
            fare = fullFare[departureAirport][arrivalAirport] * discount[i] / 100;
            total += (fare * reservation.getTicket(i));
            cout << right << setw(23) << ticketType[i] << "  TWD "
                << setw(4) << fare << " x " << reservation.getTicket(i) << endl;
        }

    cout << "\nTotal: " << total << endl;
}

void ReservationDataBase::displayReservation(Reservation reservation,
    FlightSchedule flightschedule, int numFlights)
{
    int k;
    for (k = 1; k <= numFlights; k++)
        if (reservation.getFlightNo() == flightschedule.getflights(k).getFlightNo())
            break;

    cout << "Ticket information:\n\n";
    cout << "Date: " << reservation.getDateValue() << endl;
    cout << "Flight: B7-" << reservation.getFlightNo() << endl << endl;

    int departureAirport = flightschedule.getflights(k).getDepartureAirport();
    int arrivalAirport = flightschedule.getflights(k).getArrivalAirport();

    cout << setw(9) << right << airportName[departureAirport] << " -> "
        << setw(9) << left << airportName[arrivalAirport] << endl;

    cout << setw(9) << right << flightschedule.getflights(k).getDepartureTime() << "    ";
    cout << setw(9) << left << flightschedule.getflights(k).getArrivalTime() << endl << endl;

    char ticketType[8][24] = { "", "Full Fare", "Child Fare", "Infant Fare",
                                       "Senior Citizen Fare",     "Impaired Fare",
                                       "Impaired Companion Fare", "Military Fare" };

    int total = 0;
    int fare;
    for (int i = 1; i <= 7; i++)
        if (reservation.getTicket(i) > 0)
        {
            fare = fullFare[departureAirport][arrivalAirport] * discount[i] / 100;
            total += (fare * reservation.getTicket(i));
            cout << right << setw(23) << ticketType[i] << "  TWD "
                << setw(4) << fare << " x " << reservation.getTicket(i) << endl;
        }

    cout << "\nTotal: " << total << endl;
}

void ReservationDataBase::saveReservation(const Reservation reservation)
{
    fstream outfile("Reservations.dat", ios::app | ios::binary);
    outfile.write(reinterpret_cast<const char*>(&reservation), sizeof(Reservation));
    outfile.close();
}

void ReservationDataBase::loadReservations()
{
    fstream infile("Reservations.dat", ios::in | ios::binary);
    infile.seekg(0, ios::end);
    int numReservations = static_cast<int>(infile.tellg()) / sizeof(Reservation);
    infile.seekg(0, ios::beg);
    for (int i = 0; i < numReservations; i++) {
        infile.read(reinterpret_cast<char*>(&reservations[i]), sizeof(Reservation));
    }

    setNum(numReservations);
    infile.close();
}

void ReservationDataBase::setNum(int num)
{
    ReservationDataBase::reservationsnum = num;
}
int ReservationDataBase::getNum()
{
    return reservationsnum;
}

Reservation ReservationDataBase::getreservations(int i)
{
    return reservations[i];
}